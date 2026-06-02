#include <stdio.h>

static int acquire(void) {
    printf("open\n");
    return 1; /* a handle; 0 would signal failure */
}

static void release(int handle) {
    (void)handle;
    printf("close\n");
}

int main(void) {
    int handle = acquire();
    if (handle == 0) {
        return 1; /* acquisition failed: nothing to release */
    }

    printf("use\n");
    goto cleanup; /* every later exit path funnels here so release() runs once */

cleanup:
    release(handle);
    return 0;
}
