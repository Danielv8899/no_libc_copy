#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define SYS_OPEN 2
#define SYS_CLOSE 3
#define SYS_WRITE 1
#define SYS_READ 0
#define SYS_EXIT 60

#define BUFSIZ 1024

int __open(const char* path, int flags, mode_t mode);
ssize_t __read(int fd, void *buf, size_t count);
ssize_t __write(int fd, const void *buf, size_t count);
int __exit(int status);
int __close(int fd);
size_t __strlen(const char* buf);
void __print(const char* buf);