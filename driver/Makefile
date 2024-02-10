INSTALL_DIR=modules
ifneq (${KERNELRELEASE},)
	obj-m := mycdd.o

mycdd-objs := initFunc.o exitFunc.o openDevice.o readDevice.o writeDevice.o releaseDevice.o

else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	@rm -rf ${INSTALL_DIR}
	@mkdir ${INSTALL_DIR}
	@mv -f *.mod *.order *.symvers *.o *.ko *.mod.c .*.cmd ${INSTALL_DIR}
clean:
	rm -rf ${INSTALL_DIR}
endif