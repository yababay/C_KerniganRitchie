#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define PERMS 0666

#define OPEN_MAX 20

typedef struct _iobuf {
    int cnt;
    char *ptr;
    char *base;
    int flag;
    int fd;
} FILE_C;
FILE_C iob[OPEN_MAX];

enum _flags {
    _READ = 01,
    _WRITE = 02,
    _UNBUF = 04,
    _EOF = 010,
    _ERR = 020
};

int _flushbuf(int, FILE_C *);
int fclose_c(FILE_C *);
int write(int, char *, int);
int fflush_c(FILE_C *);

int main() {

    return 0;
}

int _flushbuf(int x, FILE_C *fp) {
    unsigned nc;
    int bufsize;

    if (fp < iob || fp >= iob + OPEN_MAX) {
        return EOF;
    }
    if ((fp->flag & (_WRITE | _ERR)) != _WRITE) {
        return EOF;
    }
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL) {
        if ((fp->base = (char *)malloc(bufsize)) == NULL) {
            fp->flag |= _ERR;
            return EOF;
        }
    }
    else {
        nc = fp->ptr - fp->base;
        if (write(fp->fd, fp->base, nc) != nc) {
            fp->flag |= _ERR;
            return EOF;
        }
    }
    fp->ptr = fp->base;
    *fp->ptr++ = (char)x;
    fp->cnt = bufsize - 1;
    return x;
}

int fclose_c(FILE_C *fp) {
    int rc;

    if ((rc = fflush_c(fp)) != EOF) {
        free(fp->base);
        fp->ptr = NULL;
        fp->cnt = 0;
        fp->base = NULL;
        fp->flag &= ~(_READ | _WRITE);
    }
    return rc;
}

int fflush_c(FILE_C *fp) {
    int rc = 0;

    if (fp < iob || fp >= iob + OPEN_MAX) {
        return EOF;
    }
    if (fp->flag & _WRITE) {
        rc = _flushbuf(0, fp);
    }
    fp->ptr = fp->base;
    fp->cnt = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    
    return rc;
}
