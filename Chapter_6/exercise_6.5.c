#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void undef(char *);

int main() {
    struct nlist *nl;

    install("aaa", "Hi!");
    install("bbb", "Hello");
    
    printf("%s\n", lookup("aaa")->defn);

    install("aaa", "Hey!");
    printf("%s\n", lookup("aaa")->defn);

    undef("aaa");
    nl = lookup("aaa");
    if (nl == NULL) {
        printf("Null\n");
    }
    else {
        printf("%s\n", nl->defn);
    }
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

void undef(char *s) {
    struct nlist *np, *nprev;

    for (np = hashtab[hash(s)], nprev = NULL; 
            np != NULL;
            nprev = np, np = np->next) {
        if (strcmp(s, np->name) == 0) {
            if (nprev != NULL) {
                nprev->next = np->next;
            }
            else {
                hashtab[hash(s)] = np->next;
            }
            free((void *) np->name);
            free((void *) np->defn);
            free((void *) np);
            return;
        }
    }
}
