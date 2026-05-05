#include <stdio.h>

int main() {
    int n, i;
    int gen[10], kill[10], in[10], out[10];

    printf("Enter number of basic blocks: ");
    scanf("%d", &n);

    printf("\nEnter GEN set:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &gen[i]);
    }

    printf("\nEnter KILL set:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &kill[i]);
    }

    for (i = 0; i < n; i++) {
        in[i] = 0;
        out[i] = gen[i];
    }

    printf("\nGlobal Data Flow Analysis (Reaching Definitions)\n");
    printf("Block\tGEN\tKILL\tIN\tOUT\n");

    for (i = 0; i < n; i++) {
        in[i] = out[i] & (~kill[i]);
        out[i] = gen[i] | in[i];

        printf("%d\t%d\t%d\t%d\t%d\n",
               i + 1, gen[i], kill[i], in[i], out[i]);
    }

    return 0;
}
