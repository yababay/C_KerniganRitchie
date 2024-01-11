#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], char* buffer, int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);

int getline_c(char *s, int lim);

int main() {
    int nlines;
    char buffer[ALLOCSIZE];

    if ((nlines = readlines(lineptr, buffer, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int readlines(char *lineptr[], char *buffer, int maxlines) {
    int len, nlines;
    char line[MAXLEN];

    nlines = 0;
    while ((len = getline_c(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || buffer == NULL) {
            return -1;
        }
        else {
            line[len-1] = '\0';
            strcpy(buffer, line);
            lineptr[nlines++] = buffer;
            buffer = buffer+len;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) { 
    while (nlines-- > 0) {
        printf("%s\n", *lineptr++);
    }
}

void qsort(char *v[], int left, int right) {
    int i, last;
    
    if (left >= right) {
        return;
    }
    swap(v, left, (left+right)/2);
    last = left;

    for (i = left+1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int getline_c(char *s, int lim) {
    int c, n;

    n = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
        n++;
    }
    if (c == '\n') {
        *s++ = c;
        n++;
    }
    *s = '\0';
    return n;
}
