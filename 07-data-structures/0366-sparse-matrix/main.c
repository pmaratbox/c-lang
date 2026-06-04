#include <stdio.h>

#define MAXENTRIES 64

typedef struct {
    int row;
    int col;
    int val;
} Cell;

static Cell cells[MAXENTRIES];
static int n = 0;

static void sm_set(int row, int col, int val) {
    for (int i = 0; i < n; i++) {
        if (cells[i].row == row && cells[i].col == col) {
            cells[i].val = val;
            return;
        }
    }
    cells[n].row = row;
    cells[n].col = col;
    cells[n].val = val;
    n++;
}

static int sm_get(int row, int col) {
    for (int i = 0; i < n; i++)
        if (cells[i].row == row && cells[i].col == col)
            return cells[i].val;
    return 0; /* missing key reads as 0 */
}

int main(void) {
    sm_set(1, 1, 5);
    printf("%d %d\n", sm_get(1, 1), sm_get(0, 0));
    return 0;
}
