#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kdev_t.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/uaccess.h>


MODULE_AUTHOR("Sachin Sharma");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is simple driver implementing file operations");
MODULE_VERSION("0.0.5");