#ifndef __OPERATIONS_H__
#define __OPERATIONS_H__

struct file_operations fops =
{
    .owner = THIS_MODULE,
    .read = readDevice,
    .write = writeDevice,
    .open = openDevice,
    .release = releaseDevice,
};
#endif