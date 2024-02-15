#include <stdio.h>

#define MAXLINE 100
#define MAXPAGE 60

void fill_lines(int, int);

int main(int argc, char *argv[]) {
    int curline = 0, pageno = 1;
    FILE *fp = NULL;
    char line[MAXLINE];
    char *sp;

    if (--argc < 1) {
        printf("Usage: pagewrite file ...\n");
        return 1;
    }

    while (argc > 0) {
        if (fp == NULL) {
            fp = fopen(*++argv, "r");
            if (fp == NULL) {
                fprintf(stderr, "Error opening file %s", *argv);
                return 2;
            }
            printf("\n%s\n\n", *argv);
            curline += 3;
        }

        sp = fgets(line, MAXLINE, fp);
        if (sp == NULL) {
            fclose(fp);
            fp = NULL;
            argc--;
            fill_lines(pageno, MAXPAGE-curline);
            pageno = 1;
            curline = 0;
        }
        else {
            printf("%s", line);
            curline++;
            if (curline >= MAXPAGE) {
                printf("\t%d\n", pageno++);
                curline = 0;
            }
        }
    }
    return 0;
}

void fill_lines(int pageno, int lines) {
    int i;

    for (i = 0; i < lines; i++) {
        printf("\n");
    }
    
    printf("\t%d\n", pageno);
}
