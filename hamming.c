#include <stdio.h>
int main() {
    int d[10], r[10], p1, p2, p4, p, i;
    printf("Enter 4-bit data: ");
    for (i = 3; i >= 0; i--)
        scanf("%d", &d[i]);
    p1 = d[0] ^ d[1] ^ d[3];
    p2 = d[0] ^ d[2] ^ d[3];
    p4 = d[1] ^ d[2] ^ d[3];
    printf("Transmitted: %d%d%d%d%d%d%d\n", p1, p2, d[0], p4, d[1], d[2], d[3]);
    printf("Enter received: ");
    for (i = 6; i >= 0; i--)
        scanf("%d", &r[i]);
    p1 = r[6] ^ r[5] ^ r[3] ^ r[1];
    p2 = r[6] ^ r[4] ^ r[3] ^ r[0];
    p4 = r[5] ^ r[4] ^ r[3] ^ r[2];
    p = p4 * 4 + p2 * 2 + p1;
    if (p) {
        printf("Error at: %d\nCorrected: ", p);
        r[7 - p] ^= 1;
        for (i = 6; i >= 0; i--)
            printf("%d", r[i]);
    } else
        printf("No error\n");
    return 0;
}
