#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000

int getline_c(char *, int);
char *alloc(int);
char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort_c(char *lineptr[], int left, int right,
        int (*comp)(const char *, const char *), int reverse);
int numcmp(const char *, const char *);
int strcasecmp(const char *, const char *);

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int main(int argc, char *argv[]) {
    int nlines;
    int numeric = 0, reverse = 0, fold = 0;

    while (--argc > 0) {
        if ((*++argv)[0] == '-') {
            switch ((*argv)[1]) {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                case 'f':
                    fold = 1;
                    break;
                default:
                    printf("Usage: sort -n -r -f\n");
                    break;
            }
        }
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort_c(lineptr, 0, nlines-1,
                (int (*)(const char*, const char*))(numeric ? numcmp :
                    (fold ? strcasecmp : strcmp)),
                reverse);
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("input too big to sort\n");
        return 1;
    }
}

void qsort_c(char *v[], int left, int right,
        int (*comp)(const char *, const char *), int reverse) {
    int i, last, cmpres;

    void swap(char *v[], int, int);

    if (left >= right) {
        return;
    }

    swap(v, left, (left + right)/2);
    last = left;

    for (i = left+1; i <= right; i++) {
        cmpres = (*comp)(v[i], v[left]);
        if ((!reverse && cmpres < 0) || (reverse && cmpres >= 0)) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort_c(v, left, last-1, comp, reverse);
    qsort_c(v, last+1, right, comp, reverse);
}

int numcmp(const char *s1, const char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) {
        return -1;
    }
    else if (v1 > v2) {
        return 1;
    }
    else {
        return 0;
    }
}

void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0) {
        printf("%s\n", *lineptr++);
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

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    }
    else {
        return 0;
    }
}

int getline_c(char *s, int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int strcasecmp(const char *s, const char *t) {
    int sf, tf;

    for(;;++s, ++t) {
        if (!*s && !*t) {
            return 0;
        }
        if (*s >= 'A' && *s <= 'Z') {
            sf = *s - ('A' - 'a');
        }
        else {
            sf = *s;
        }

        if (*t >= 'A' && *t <= 'Z') {
            tf = *t - ('A' - 'a');
        }
        else {
            tf = *t;
        }

        if (sf > tf) {
            return 1;
        }
        if (tf > sf) {
            return -1;
        }
    }
}
