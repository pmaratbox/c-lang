#include <stdio.h>

#define MAXKEYS 64

static int keys[MAXKEYS];
static int counts[MAXKEYS];
static int n = 0;

static int slot(int key) {
    for (int i = 0; i < n; i++)
        if (keys[i] == key)
            return i;
    keys[n] = key;
    counts[n] = 0;
    return n++;
}

static void ms_add(int key) {
    counts[slot(key)]++;
}

static void ms_remove(int key) {
    int i = slot(key);
    if (counts[i] > 0) counts[i]--;
}

static int ms_count(int key) {
    return counts[slot(key)];
}

int main(void) {
    ms_add(1);
    ms_add(1);
    ms_add(2);
    int a = ms_count(1);
    ms_remove(1);
    int b = ms_count(1);
    printf("%d %d\n", a, b);
    return 0;
}
