#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100
#define LINECOUNT 100

char buf[BUFSIZE];
int bufp = 0;

struct tnode {
    char *word;
    int lines[LINECOUNT];
    int index;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int, int *);
int getch(void);
void ungetch(int);
struct tnode *talloc(void);
int isbadword(char *);

int main() {
    struct tnode *root;
    char word[MAXWORD];
    int curline = 1;

    root = NULL;
    while (getword(word, MAXWORD, &curline) != EOF) {
        if (isalpha(word[0]) && !isbadword(word)) {
            root = addtree(root, word, curline);
        }
    }
    treeprint(root);
    return 0;
}

struct tnode *addtree(struct tnode *p, char *w, int curline) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->lines[0] = curline;
        p->index = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0) {
        p->lines[p->index++] = curline;
    }
    else if (cond < 0) {
        p->left = addtree(p->left, w, curline);
    }
    else {
        p->right = addtree(p->right, w, curline);
    }
    return p;
}

void treeprint(struct tnode *p) {
    int i;
    if (p != NULL) {
        treeprint(p->left);
        printf("%s\t.Lines:", p->word);
        for(i = 0; i < p->index; i++) {
            printf(" %d", p->lines[i]);
        }
        printf("\n");
        treeprint(p->right);
    }
}

int getword(char *word, int lim, int *curline) {
    int c, d;
    char *w = word;

    while (isspace(c = getch())) {
        if (c == '\n') {
            (*curline)++;
        }
    }

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

int isbadword(char *w) {
    return (strlen(w) <= 1 || !strcmp(w, "the") ||
            !strcmp(w, "and") || !strcmp(w, "or"));
}
