#include <stdio.h>

#define CAP 2

typedef struct {
    int key;
    int val;
    int used; /* recency timestamp */
} Entry;

static Entry cache[CAP];
static int count = 0;
static int clock_ = 0;

static int find(int key) {
    for (int i = 0; i < count; i++)
        if (cache[i].key == key)
            return i;
    return -1;
}

static int lru_get(int key) {
    int i = find(key);
    if (i < 0) return -1;
    cache[i].used = ++clock_;
    return cache[i].val;
}

static void lru_put(int key, int val) {
    int i = find(key);
    if (i >= 0) {
        cache[i].val = val;
        cache[i].used = ++clock_;
        return;
    }
    if (count < CAP) {
        i = count++;
    } else {
        i = 0;
        for (int j = 1; j < count; j++)
            if (cache[j].used < cache[i].used)
                i = j;
    }
    cache[i].key = key;
    cache[i].val = val;
    cache[i].used = ++clock_;
}

int main(void) {
    lru_put(1, 1);
    lru_put(2, 2);
    lru_get(1);
    lru_put(3, 3);
    printf("%d %d\n", lru_get(1), lru_get(2));
    return 0;
}
