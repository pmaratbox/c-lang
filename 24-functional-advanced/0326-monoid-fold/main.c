#include <stdio.h>
#include <string.h>

/* A monoid is an identity plus an associative combine. A generic fold
   over void* elements works for any monoid given its ops. */
typedef struct {
    void *(*combine)(void *acc, const void *x);
} Monoid;

static void *str_combine(void *acc, const void *x) {
    strcat((char *)acc, (const char *)x);
    return acc;
}

static void *int_combine(void *acc, const void *x) {
    *(int *)acc += *(const int *)x;
    return acc;
}

static void *fold(Monoid m, void *identity, const void **xs, int n) {
    void *acc = identity;
    for (int i = 0; i < n; i++) acc = m.combine(acc, xs[i]);
    return acc;
}

int main(void) {
    char buf[16] = "";                 /* string identity: "" */
    const char *strs[] = {"a", "b", "c"};
    Monoid strmon = {str_combine};
    fold(strmon, buf, (const void **)strs, 3);

    int sum = 0;                       /* int sum identity: 0 */
    int ints[] = {1, 2, 3};
    const void *iptrs[] = {&ints[0], &ints[1], &ints[2]};
    Monoid intmon = {int_combine};
    fold(intmon, &sum, iptrs, 3);

    printf("%s %d\n", buf, sum);
    return 0;
}
