#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define GRLENGTH 6
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
char *reduce(char *, int);
int getch(void);
void ungetch(int);
struct tnode *talloc(void);

int main(int argc, char **argv) {
    struct tnode *root;
    char word[MAXWORD];
    int length = GRLENGTH;

    if (argc > 1) {
        if ((*++argv)[0] == '-' && (*argv)[1] == 'l') {
            length = atoi(*++argv);
        }
        else {
            printf("usage: count [-l <number>]\n");
            return 1;
        }
    }

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, reduce(word, length));
        }
    }
    treeprint(root);
    return 0;
}

struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
    }
    else if (cond < 0) {
        p->left = addtree(p->left, w);
    }
    else {
        p->right = addtree(p->right, w);
    }
    return p;
}

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

int getword(char *word, int lim) {
    int c, d;
    char *w = word;

    while (isspace(c = getch()))
        ;

    if (c != EOF) {
        *w++ = c;
    }
    if (isalpha(c) || c == '_' || c == '#') {
        for (; --lim > 0; w++) {
            if (!isalnum(*w = getch())) {
                ungetch(*w);
                break;
            }
        }
    }
    else if (c == '\'' || c == '"') {
        for (; --lim > 0; w++) {
            if ((*w = getch()) == '\\') {
                *++w = getch();
            }
            else if (*w == c) {
                w++;
                break;
            }
            else if (*w == EOF) {
                break;
            }
        }
    }
    else if (c == '/') {
        if ((d = getch()) == '*') {
            while ((c = getch()) != EOF) {
                if (c == '*') {
                    if ((c = getch()) == '/') {
                        break;
                    }
                    else {
                        ungetch(c);
                    }
                }
            }
        }
        else {
            ungetch(d);
        }
    }
    *w = '\0';
    return c;
}

char *reduce(char *w, int n) {
    *(w+n) = '\0';
    return w;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    }
    else {
        buf[bufp++] = c;
    }
}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}
