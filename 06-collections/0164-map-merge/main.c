#include <stdio.h>
#include <string.h>

typedef struct {
    char key;
    int value;
} Entry;

int main(void) {
    Entry left[]  = {{'a', 1}, {'b', 2}};
    Entry right[] = {{'b', 3}, {'c', 4}};
    int ln = sizeof(left) / sizeof(left[0]);
    int rn = sizeof(right) / sizeof(right[0]);

    Entry merged[64];
    int n = 0;
    for (int i = 0; i < ln; i++) {
        merged[n++] = left[i];
    }
    for (int i = 0; i < rn; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (merged[j].key == right[i].key) {
                merged[j].value = right[i].value; /* right wins */
                found = 1;
                break;
            }
        }
        if (!found) {
            merged[n++] = right[i];
        }
    }

    /* sort by key (insertion sort) */
    for (int i = 1; i < n; i++) {
        Entry e = merged[i];
        int j = i - 1;
        while (j >= 0 && merged[j].key > e.key) {
            merged[j + 1] = merged[j];
            j--;
        }
        merged[j + 1] = e;
    }

    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%c:%d" : " %c:%d", merged[i].key, merged[i].value);
    }
    printf("\n");
    return 0;
}
