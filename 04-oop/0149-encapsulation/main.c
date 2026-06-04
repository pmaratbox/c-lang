#include <stdio.h>

typedef struct {
    int balance;
} Account;

static void deposit(Account *a, int amount) {
    a->balance += amount;
}

static int get_balance(const Account *a) {
    return a->balance;
}

int main(void) {
    Account a = { .balance = 100 };
    deposit(&a, 50);
    printf("%d\n", get_balance(&a));
    return 0;
}
