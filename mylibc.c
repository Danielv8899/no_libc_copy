#include "mylibc.h"

int __open(const char* path, int flags, mode_t mode){
    int retval;
    asm volatile("syscall\n\t":"=a"(retval):"a"(SYS_OPEN),"D"(path),"S"(flags),"d"(mode));
    return retval;
}

ssize_t __read(int fd, void *buf, size_t count){
    ssize_t retval;
    asm __volatile("syscall\n\t":"=a"(retval):"a"(SYS_READ),"D"(fd),"S"(buf),"d"(count));
    return retval;
}

ssize_t __write(int fd, const void *buf, size_t count){
    ssize_t retval;
    asm __volatile("syscall\n\t":"=a"(retval):"a"(SYS_WRITE),"D"(fd),"S"(buf),"d"(count));
    return retval;
}

int __exit(int status){
    int retval;
    asm __volatile("syscall\n\t":"=a"(retval):"a"(SYS_EXIT),"D"(status));
    return retval;
}

int __close(int fd){
    int retval;
    asm __volatile("syscall\n\t":"=a"(retval):"a"(SYS_CLOSE),"D"(fd));
    return retval;
}

size_t __strlen(const char* buf){
    const char* start = buf;
    while(*buf!='\0'){
        buf++;
    }
    return buf-start;
}

void __print(const char* buf){
    __write(1,buf,__strlen(buf));
}