#ifndef __DECLARATIONS_H__
#define __DECLARATIONS_H__

extern int nod;
extern dev_t devId;
extern struct class *dev_class;

extern struct cdev dev;

extern uint8_t *kernel_buffer;

int openDevice(struct inode *, struct file*);
int releaseDevice(struct inode *, struct file *);
ssize_t readDevice(struct file*, char __user *, size_t, loff_t*);
ssize_t writeDevice(struct file*, const char __user *, size_t, loff_t*);

#endif