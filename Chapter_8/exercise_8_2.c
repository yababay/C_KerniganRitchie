#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define PERMS 0666

#define OPEN_MAX 20

typedef struct _iobuf {
    int cnt;
    char *ptr;
    char *base;
    int isread;
    int iswrite;
    int isunbuf;
    int iseof;
    int iserr;
    int fd;
} FILE_C;
FILE_C iob[OPEN_MAX];

FILE_C *fopen_c(char *, char *);
long lseek(int, long, int);
int write(int, char *, int);
int read(int, char *, int);
int close(int);

int main() {
    FILE_C *fp;
    fp = fopen_c("test.txt", "a");
    write(fp->fd, "Hello, world!\n", 15);

    close(fp->fd);

    return 0;
}

FILE_C *fopen_c(char *name, char *mode) {
    int fd;
    FILE_C *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a') {
        return NULL;
    }
    for (fp = iob; fp < iob + OPEN_MAX; fp++) {
        if (!fp->isread && !fp->iswrite) {
            break;
        }
    }
    if (fp >= iob + OPEN_MAX) {
        return NULL;
    }

    if (*mode == 'w') {
        fd = creat(name, PERMS);
    }
    else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == -1) {
            fd = creat(name, PERMS);
        }
        lseek(fd, 0L, 2);
    }
    else {
        fd = open(name, O_RDONLY, 0);
    }
    if (fd == -1) {
        return NULL;
    }
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->isread = (*mode == 'r');
    fp->iswrite = !fp->isread;
    
    return fp;
}

int _fillbuf_c(FILE_C *fp) {
    int bufsize;

    if (!fp->isread || fp->iseof || fp->iserr) {
        return EOF;
    }
    bufsize = fp->isunbuf ? 1 : BUFSIZ;
    if (fp->base == NULL) {
        if ((fp->base = (char *) malloc(bufsize)) == NULL) {
            return EOF;
        }
    }
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1) {
            fp->iseof = 1;
        }
        else {
            fp->iserr = 1;
        }
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}

