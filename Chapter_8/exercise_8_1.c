#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

void filecopy(int, int);
int read(int, char *, int);
int write(int, char *, int);
int close(int);

int main(int argc, char *argv[]) {
    int fp;
    char *prog = argv[0];

    if (argc == 1) {
        filecopy(0, 1);
    }
    else {
        while (--argc > 0) {
            if ((fp = open(*++argv, O_RDONLY, 0)) == -1) {
                write(2, prog, strlen(prog));
                write(2, ": can't open ", 14);
                write(2, *argv, strlen(*argv));
                write(2, "\n", 2);
                exit(1);
            }
            else {
                filecopy(fp, 1);
                close(fp);
            }
        }
    }
    if (ferror(stdout)) {
        write(2, prog, strlen(prog));
        write(2, ": error writing stdout\n", 24);
        exit(2);
    }
    exit(0);
}

void filecopy(int ifp,int ofp) {
    char buf[BUFSIZ];
    int n;

    while ((n = read(ifp, buf, BUFSIZ)) > 0) {
        write(ofp, buf, n);
    }
}
