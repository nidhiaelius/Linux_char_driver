#include "headers.h"
#include "defaults.h"
#include "declarations.h"
// #include "operations.h"

ssize_t writeDevice(struct file *file, const char __user *buf, size_t len, loff_t *off)
{
    printk(KERN_INFO "%s: Start\n", __func__);

    if(copy_from_user(kernel_buffer, buf, len))
    {
        pr_err("Data Write Error\n");
    }

    printk(KERN_INFO "%s: End\n", __func__);
    return len;
}