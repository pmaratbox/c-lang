#include <stdio.h>

typedef struct {
    char key;
    int count;
    int order; /* first-seen index, used as tiebreaker */
} Count;

int main(void) {
    char xs[] = {'a', 'b', 'a', 'c', 'b', 'a'};
    int n = sizeof(xs) / sizeof(xs[0]);
    int k = 2;

    Count counts[64];
    int m = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < m; j++) {
            if (counts[j].key == xs[i]) {
                counts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            counts[m].key = xs[i];
            counts[m].count = 1;
            counts[m].order = m;
            m++;
        }
    }

    /* sort by count desc, then first-seen order asc */
    for (int i = 1; i < m; i++) {
        Count c = counts[i];
        int j = i - 1;
        while (j >= 0 && (counts[j].count < c.count ||
               (counts[j].count == c.count && counts[j].order > c.order))) {
            counts[j + 1] = counts[j];
            j--;
        }
        counts[j + 1] = c;
    }

    for (int i = 0; i < k && i < m; i++) {
        printf(i == 0 ? "%c" : " %c", counts[i].key);
    }
    printf("\n");
    return 0;
}
