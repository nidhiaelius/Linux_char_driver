#include "headers.h"
#include "defaults.h"
#include "declarations.h"
// #include "operations.h"

int releaseDevice(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "%s: Start\n", __func__);
    kfree(kernel_buffer);
    printk(KERN_INFO "%s: End\n", __func__);
    return 0;
}