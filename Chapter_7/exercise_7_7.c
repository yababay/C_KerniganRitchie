#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline_c(char *s, int lim);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    char *pattern, *sp;
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;
    FILE *fp = NULL;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0])) {
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }

    if (argc-- < 1) {
        printf("Usage: find -x -n pattern file ...\n");
    }
    else if (argc == 0) {
        while (getline_c(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number) {
                    printf("%ld:", lineno);
                }
                printf("%s", line);
                found++;
            }
        }
    }
    else {
        pattern = *argv;
        while (argc > 0) {
            if (fp == NULL) {
                fp = fopen(*++argv, "r");
                if (fp == NULL) {
                    fprintf(stderr, "Error opening file %s", *argv);
                    break;
                }
                lineno = 0;
            }

            sp = fgets(line, MAXLINE, fp);
            if (sp != NULL) {
                lineno++;
                if ((strstr(line, pattern) != NULL) != except) {
                    if (number) {
                        printf("%s %ld:", *argv, lineno);
                    }
                    printf("%s", line);
                    found++;
                }
            }
            else {
                fclose(fp);
                fp = NULL;
                argc--;
            }
        }
    }
    return found;
}

int getline_c(char *s, int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        *s++ = c;
    }

    if (c == '\n') {
        *s++ = c;
        ++i;
    }
    *s = '\0';
    return i;
}
