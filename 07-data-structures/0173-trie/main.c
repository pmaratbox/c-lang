#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode *children[26];
    int end;
} TrieNode;

static TrieNode *new_node(void) {
    TrieNode *n = calloc(1, sizeof(TrieNode));
    return n;
}

static void insert(TrieNode *root, const char *word) {
    TrieNode *cur = root;
    for (const char *p = word; *p; p++) {
        int i = *p - 'a';
        if (!cur->children[i]) cur->children[i] = new_node();
        cur = cur->children[i];
    }
    cur->end = 1;
}

static int search(TrieNode *root, const char *word) {
    TrieNode *cur = root;
    for (const char *p = word; *p; p++) {
        int i = *p - 'a';
        if (!cur->children[i]) return 0;
        cur = cur->children[i];
    }
    return cur->end;
}

int main(void) {
    TrieNode *root = new_node();
    insert(root, "cat");
    insert(root, "car");
    printf("%s %s\n", search(root, "car") ? "yes" : "no",
                      search(root, "can") ? "yes" : "no");
    return 0;
}
