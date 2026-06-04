#include <stdio.h>

int main(void) {
    int coins[] = { 10, 10, 5 };
    int total = 0;
    for (int i = 0; i < 3; i++) {
        total += coins[i];
        if (total >= 25) {
            printf("dispensed\n");
            break;
        }
    }
    return 0;
}
