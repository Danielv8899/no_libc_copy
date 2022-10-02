#include "mylibc.h"

__attribute__((force_align_arg_pointer))
void _start(int dummy1, int dummy2, int dummy3, int dummy4, int dummy5, int dummy6, char *argv0){

    int argc = (int)(long)__builtin_return_address(0); 
    char **argv = &argv0;

    int input_fd, output_fd, bytes_read;
    char buf[BUFSIZ] = {0};
    size_t flags, mode;

    mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    flags = O_WRONLY | O_CREAT | O_TRUNC;

    if (argc != 3){
        __print("usage: copy [source] [destination]\n");
        __exit(-1);
    }

    if((input_fd = __open(argv[1],O_RDONLY,0))<0){
        __print("opening source failed\n");
        __exit(-1);
    }

    if((output_fd = __open(argv[2],flags,mode)) <0){
        __print("opening destination failed\n");
        __exit(-1);
    }

    while((bytes_read = __read(input_fd,buf,BUFSIZ)) > 0){
        if( __write(output_fd,buf,bytes_read) != bytes_read){
            __print("failed writing whole buffer\n");
            __exit(-1);
        }
    }
    if(bytes_read <0){
        __print("failed reading from source\n");
        __exit(-1);
    }

    if(__close(input_fd) <0){
        __print("failed closing input_fd\n");
    }

    if(__close(output_fd) <0){
        __print("failed closing output_fd\n");
    }
    __exit(0);
}

