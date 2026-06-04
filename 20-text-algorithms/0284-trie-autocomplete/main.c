#include <stdio.h>
#include <string.h>

typedef struct Node {
    struct Node *child[26];
    int isWord;
} Node;

static Node pool[256];
static int poolUsed = 0;

static Node *newNode(void) {
    return &pool[poolUsed++];
}

static void insert(Node *root, const char *w) {
    Node *cur = root;
    for (const char *p = w; *p; p++) {
        int c = *p - 'a';
        if (!cur->child[c]) cur->child[c] = newNode();
        cur = cur->child[c];
    }
    cur->isWord = 1;
}

static int g_first = 1;

static void dfs(Node *node, char *buf, int depth) {
    if (node->isWord) {
        buf[depth] = '\0';
        if (!g_first) printf(" ");
        printf("%s", buf);
        g_first = 0;
    }
    for (int c = 0; c < 26; c++) {
        if (node->child[c]) {
            buf[depth] = (char)('a' + c);
            dfs(node->child[c], buf, depth + 1);
        }
    }
}

int main(void) {
    Node *root = newNode();
    insert(root, "car");
    insert(root, "card");
    insert(root, "dog");

    const char *prefix = "car";
    Node *cur = root;
    for (const char *p = prefix; *p; p++) {
        cur = cur->child[*p - 'a'];
        if (!cur) { printf("\n"); return 0; }
    }

    char buf[64];
    int plen = (int)strlen(prefix);
    strcpy(buf, prefix);
    dfs(cur, buf, plen);
    printf("\n");
    return 0;
}
