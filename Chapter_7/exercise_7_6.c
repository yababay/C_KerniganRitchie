#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define TRUE 1

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    char lin1[MAXLINE], lin2[MAXLINE];
    char *sp1, *sp2;

    if (argc != 3) {
        printf("Usage: filecmp filename1 filename2\n");
        return 1;
    }

    fp1 = fopen(*++argv, "r");
    if (fp1 == NULL) {
        fprintf(stderr, "Can't open file %s\n", *argv);
        return 1;
    }

    fp2 = fopen(*++argv, "r");
    if (fp2 == NULL) {
        fprintf(stderr, "Can't open file %s\n", *argv);
        return 1;
    }

    do {
        sp1 = fgets(lin1, MAXLINE, fp1);
        sp2 = fgets(lin2, MAXLINE, fp2);
        if (sp1 == NULL && sp2 == NULL) {
            printf("Files are identical\n");
            break;
        }
        if (sp1 == NULL) {
            printf("First file ends\n\nSecond:\n%s\n", lin2);
            break;
        }
        if (sp2 == NULL) {
            printf("First:\n%s\nSecond file ends\n", lin1);
            break;
        }

        if (strcmp(lin1, lin2)) {
            printf("First:\n%s\nSecond:\n%s\n", lin1, lin2);
            break;
        }
    } while (TRUE);

    fclose(fp1);
    fclose(fp2);

    return 0;
}
