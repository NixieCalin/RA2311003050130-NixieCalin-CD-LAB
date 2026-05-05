#include <stdio.h>

int main() {
    int i, n;
    char op[5], arg1[5], arg2[5], result[5];

    printf("Enter number of statements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nStatement %d\n", i + 1);
        printf("Operator: ");
        scanf("%s", op);
        printf("Operand 1: ");
        scanf("%s", arg1);
        printf("Operand 2: ");
        scanf("%s", arg2);
        printf("Result: ");
        scanf("%s", result);

        printf("\nGenerated Target Code:\n");
        printf("MOV %s, R1\n", arg1);
        printf("MOV %s, R2\n", arg2);

        if (op[0] == '+')
            printf("ADD R1, R2\n");
        else if (op[0] == '-')
            printf("SUB R1, R2\n");
        else if (op[0] == '*')
            printf("MUL R1, R2\n");
        else if (op[0] == '/')
            printf("DIV R1, R2\n");

        printf("MOV R1, %s\n", result);
    }

    return 0;
}
