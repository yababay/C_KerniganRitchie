#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEF_LINES 10
#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writenlines(char *lineptr[], int nlines, int lines);
int getline_c(char *s, int n);
char *alloc(int n);

int main(int argc, char *argv[]) {
    int lines, nlines;

    lines = DEF_LINES;

    if (argc > 1 && *argv[1] == '-') {
        lines = atoi(++argv[1]);
    }
    if (lines < 0) {
        lines = 0;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (lines > nlines) {
            lines = nlines;
        }
        writenlines(lineptr, nlines, lines);
        return 0;
    }
    else {
        printf("error: input too big\n");
        return 1;
    }
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline_c(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        }
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writenlines(char *lineptr[], int nlines, int lines) {
    int i;

    for (i = 0; i < lines; i++) {
        printf("%s\n", lineptr[nlines-lines+i]);
    }
}

int getline_c(char *s, int lim) {
    int c, i;
    i = 0;

    while(--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        *s++ = c;
        ++i;
    }
    if (c == '\n') {
        *s++ = c;
        ++i;
    }
    *s = '\0';
    return i;
}

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    }
    else {
        return 0;
    }
}
