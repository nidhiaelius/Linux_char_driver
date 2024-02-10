# User Data Read and Write
This implements the complete driver code for read and write operations from user. In order to test we need the following:
1. Driver code (Kernel space program)
2. User application ==> this will be doing the data read and write operations using the device file name of the driver present in the `/dev/` directory.

we will send the **string** data to driver and then we will be reading back from the driver. Driver should return the same string which we have written. 

In order to make it more practical we can read and write data from two different applications.

## Driver Code
In this we will be implementing the following operations of device file:
1. Open file
2. Write to file
3. Read from driver
4. Close file

## Required Functions

### kmalloc()
It is used to allocate the memory in **kernel space**. 
```void *kmalloc(size_t size, gfp_t flags);```

**size**: required bytes of memory

**flags**: type of required memory bytes. It can be of any of the following type:

* GFP_USER
* GFP_KERNEL
* GFP_ATOMIC
* ......

### kfree()
It is used to free up the allocated memory in user space.
```void kfree(const void *objp);```

***objp**: pointer returned by kmalloc.

### copy_from_user
This function is used to copy a block of data from user space to kernel space. This function will go into the **writeDevice** function.

```unsigned long copy_from_user(void *to, const void __user *from, unsigned long n);```

`to`: Destination address in the kernel space

`from`: source address in the user space

`n`: number of bytes to copy.

It returns the number of bytes that could not be copied. On success, this will return 0.

### copy_to_user
It is used to copy a block of data into userspace i.e. from kernel space to user space. This function goes into the **readDevice** function. 

```unsigned long copy_to_user(const void __user *to, const void *from, unsigned long n);```

`to`: destination address in the user space

`from`: source address in the kernel space

`n`: Number of bytes to copy

## Example
This is a code snippet bsed on required functions only.


```
#define MEM_SIZE 1024
uint8_t *kernel_buffer
```

**open call**

```
static int openDevice(struct inode *inode, struct file *file)
{
    if((kernel_buffer = kmalloc(MEM_SIZE, GFP_KERNEL)) == 0)
    {
        return -1;
    }

    return 0;
}
```

**write call**
```
static ssize_t writeDevice(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
    copy_from_user(kernel_buffer, buf, len);
    return len;
}
```

**read call**
```
static ssize_t readDevice(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
    copy_to_user(buf, kernel_buffer, MEM_SIZE);
    return MEM_SIZE;
}
```

**close**

We need to close the device and clear the device allocated file.
```
static int releaseDevice(struct inode *inode, struct file *file)
{
    kfree(kernel_buffer);
    return 0;
}
```