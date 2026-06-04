#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *data;
} RealSubject;

typedef struct {
    RealSubject *real;
} Proxy;

const char *proxy_request(Proxy *p) {
    if (p->real == NULL) {
        p->real = malloc(sizeof(RealSubject));
        p->real->data = "loaded";
    }
    return p->real->data;
}

int main(void) {
    Proxy p = {NULL};
    printf("%s\n", proxy_request(&p));
    free(p.real);
    return 0;
}
