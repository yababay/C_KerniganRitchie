#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define MAXWORDS 1000
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct wordcount {
    char *word;
    int count;
};

struct tnode *addtree(struct tnode *, struct wordcount);
void addword(struct wordcount *, char *, int *);
void treeprint(struct tnode *);
int getword(char *, int);
int getch(void);
void ungetch(int);
struct tnode *talloc(void);

int main() {
    struct tnode *root;
    char word[MAXWORD];
    struct wordcount words[MAXWORDS];
    int dw = 0, i;

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            addword(words, word, &dw);
        }
    }

    for (i = 0 ; i < dw; i++) {
        root = addtree(root, words[i]);
    }
    treeprint(root);
    return 0;
}

struct tnode *addtree(struct tnode *p, struct wordcount w) {

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w.word);
        p->count = w.count;
        p->left = p->right = NULL;
    }
    else if (w.count > p->count) {
        p->left = addtree(p->left, w);
    }
    else {
        p->right = addtree(p->right, w);
    }
    return p;
}

void addword(struct wordcount *wc, char *w, int *n) {
    struct wordcount *element = wc;
    int i;

    for (i = 0; i < *n; i++) {
        if (strcmp(w, element[i].word) == 0) {
            element[i].count++;
            return;
        }
    }
    element[i].word = strdup(w);
    element[i].count = 1;
    (*n)++;
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
