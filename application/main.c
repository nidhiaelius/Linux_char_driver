#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

char write_buf[1024], read_buf[1024];

int main()
{
    int fd;
    char option;

    fd = open("/dev/Sachin_device", O_RDWR);
    if(fd < 0)
    {
        printf("Cannot open device file..\n");
        return 0;
    }

    while(1)
    {
        printf("***********Enter your choice****************\n");
        printf("1: Write \n");
        printf("2: Read\n");
        printf("3: Exit\n");
        scanf("%c", &option);
        getchar();
        switch(option){
            case '1':
                printf("Enter the string to write into the driver....\n");
                scanf("%s", write_buf);
                getchar();
                printf("Data Writing...");
                write(fd, write_buf, strlen(write_buf) + 1);
                printf("Done\n");
                break;
            case '2':
                printf("Data Reading....");
                read(fd, read_buf, 1024);
                printf("Data: %s\n", read_buf);
                break;
            case '3':
                close(fd);
                exit(1);
                break;
            default:
                printf("Enter a valid choice\n");
                break;
        }
    }
    close(fd);

    return 0;
}