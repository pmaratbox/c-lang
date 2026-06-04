#include <stdio.h>
#include <string.h>

int main(void) {
    const char *a = "999999999999";
    const char *b = "1";
    int la = (int)strlen(a), lb = (int)strlen(b);
    char out[64];
    int oi = 0, carry = 0;
    int i = la - 1, j = lb - 1;
    while (i >= 0 || j >= 0 || carry) {
        int da = i >= 0 ? a[i--] - '0' : 0;
        int db = j >= 0 ? b[j--] - '0' : 0;
        int sum = da + db + carry;
        carry = sum / 10;
        out[oi++] = (char)('0' + sum % 10);
    }
    for (int k = oi - 1; k >= 0; k--) putchar(out[k]);
    putchar('\n');
    return 0;
}
