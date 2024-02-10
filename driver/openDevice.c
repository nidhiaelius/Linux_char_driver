#include "headers.h"
#include "defaults.h"
#include "declarations.h"
// #include "operations.h"

int openDevice(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "%s: Start\n", __func__);

    /*-----create or allocate memory----------*/
    if((kernel_buffer = kmalloc(MEM_SIZE, GFP_KERNEL)) == 0)
    {
        pr_info("Cannot allocate memory in kernel\n");
        return -1;
    }

    strcpy(kernel_buffer, "hello_sachin");
    
    printk(KERN_INFO "%s: End\n", __func__);
    return 0;
}