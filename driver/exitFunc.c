#include "headers.h"
#include "defaults.h"
#include "declarations.h"
// #include "operations.h"


static void __exit exitFunc(void)
{
    printk(KERN_INFO "%s: Start\n", __func__);
    
    device_destroy(dev_class, devId);
    class_destroy(dev_class);
    cdev_del(&dev);
    unregister_chrdev_region(devId, NOD);
    printk(KERN_INFO "%s: End\n", __func__);
}
module_exit(exitFunc);