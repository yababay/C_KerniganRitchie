#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE 101
#define MAXLINE 1000
#define DEFSTRING "#define"
#define TABLELEN 100
#define DEF

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
int getline_c(char line[], int max);
void processdef(char *);

int main() {
    char line[MAXLINE];
    int l;

    while ((l = getline_c(line, MAXLINE)) > 0) {
        if (l > 10 && strncmp(line, DEFSTRING, strlen(DEFSTRING)) == 0) {
            processdef(line);
        }
    }

    printf("%s\n%s\n%s\n%s\n", lookup("HASHSIZE")->defn,
            lookup("MAXLINE")->defn, 
            lookup("DEFSTRING")->defn,
            lookup("DEF")->defn);
    return 0;
}

unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            return np;
        }
    }
    return NULL;
}

struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL) {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else {
        free((void *) np->defn);
    }
    if ((np->defn = strdup(defn)) == NULL) {
        return NULL;
    }
    return np;
}

int getline_c(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

void processdef(char *l) {
    char *p = l+7, *pp;
    char s[TABLELEN], t[TABLELEN];

    while (isspace(*++p))
        ;
    pp = s;
    while (isalpha(*p)) {
        *pp++ = *p++;
    }
    *pp = '\0';
    
    while (isspace(*p)) {
        p++;
    }
    pp = t;
    while (*p != '\n' && *p != EOF) {
        *pp++ = *p++;
    }
    *pp = '\0';

    install(s, t);
}
