#include <stdio.h>
#include <string.h>

int main() {
    char prod[10][30];
    int n;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: A->Aa|b):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", prod[i]);
    }

    printf("\nGiven Grammar:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", prod[i]);
    }

    printf("\nAfter Eliminating Left Recursion:\n");

    for (int i = 0; i < n; i++) {
        char A = prod[i][0];
        char *rhs = strstr(prod[i], "->") + 2;

        if (rhs[0] == A) {
            printf("%c -> %s%c'\n", A, rhs + 1, A);
            printf("%c' -> %s%c' | ε\n", A, rhs + 1, A);
        } else {
            printf("%s\n", prod[i]);
        }
    }

    printf("\nNote:\n");
    printf("Ambiguity elimination and left factoring are grammar dependent\n");
    printf("and are explained theoretically.\n");

    return 0;
}
