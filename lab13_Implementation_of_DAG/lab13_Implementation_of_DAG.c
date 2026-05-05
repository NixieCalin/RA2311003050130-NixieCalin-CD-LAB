#include <stdio.h>
#include <string.h>

struct DAG {
    char op;
    char left[5];
    char right[5];
    char result[5];
};

int main() {
    struct DAG dag[10];
    int n, i;

    printf("Enter number of expressions: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nExpression %d\n", i + 1);
        printf("Operator: ");
        scanf(" %c", &dag[i].op);
        printf("Operand 1: ");
        scanf("%s", dag[i].left);
        printf("Operand 2: ");
        scanf("%s", dag[i].right);
        printf("Result: ");
        scanf("%s", dag[i].result);
    }

    printf("\nDAG Representation\n");
    printf("Op\tLeft\tRight\tResult\n");
    for (i = 0; i < n; i++) {
        printf("%c\t%s\t%s\t%s\n",
               dag[i].op,
               dag[i].left,
               dag[i].right,
               dag[i].result);
    }

    return 0;
}
