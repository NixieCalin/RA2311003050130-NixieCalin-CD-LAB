#include <stdio.h>
#include <string.h>

struct quad {
    char op[5], arg1[5], arg2[5], result[5];
} q[10];

int main() {
    int n;

    printf("Enter number of expressions: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nExpression %d\n", i + 1);
        printf("Operator: ");
        scanf("%s", q[i].op);
        printf("Argument 1: ");
        scanf("%s", q[i].arg1);
        printf("Argument 2: ");
        scanf("%s", q[i].arg2);
        printf("Result: ");
        scanf("%s", q[i].result);
    }

    /* Quadruple */
    printf("\nQUADRUPLE TABLE\n");
    printf("Op\tArg1\tArg2\tResult\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%s\t%s\t%s\n", q[i].op, q[i].arg1, q[i].arg2, q[i].result);
    }

    /* Triple */
    printf("\nTRIPLE TABLE\n");
    printf("Index\tOp\tArg1\tArg2\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%s\t%s\n", i, q[i].op, q[i].arg1, q[i].arg2);
    }

    /* Indirect Triple */
    printf("\nINDIRECT TRIPLE TABLE\n");
    printf("Pointer\tIndex\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, i);
    }

    return 0;
}
