#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _iobuf {
    int cnt;
    char *ptr;
    char *base;
    int flag;
    int fd;
} FILE_C;

enum _flags {
    _READ = 01,
    _WRITE = 02,
    _UNBUF = 04,
    _EOF = 010,
    _ERR = 020
};

int fseek_c(FILE_C *, long, int);
int write(int, char *, int);
long lseek(int, long, int);

int main() {

    return 0;
}

int fseek_c(FILE_C *fp, long offset, int origin) {
    unsigned nc;
    long rc = 0;

    if (fp->flag & _READ) {
        if (origin == 1) {
            offset -= fp->cnt;
        }
        rc = lseek(fp->fd, offset, origin);
        fp->cnt = 0;
    }
    else if (fp->flag & _WRITE) {
        if ((nc = fp->ptr - fp->base) > 0) {
            if (write(fp->fd, fp->base, nc) != nc) {
                rc = -1;
            }
        }
        if (rc != -1) {
            rc = lseek(fp->fd, offset, origin);
        }
    }
    
    return (rc == -1) ? -1 : 0;
}
