#include <stdio.h>
#include <string.h>

char prod[10][20];
int n;

void printLR0Items() {
    printf("\nLR(0) Items:\n");

    for (int i = 0; i < n; i++) {
        char lhs = prod[i][0];
        char *rhs = strchr(prod[i], '>') + 1;
        int len = strlen(rhs);

        for (int dot = 0; dot <= len; dot++) {
            printf("%c -> ", lhs);
            for (int j = 0; j < len; j++) {
                if (j == dot)
                    printf(".");
                printf("%c", rhs[j]);
            }
            if (dot == len)
                printf(".");
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: E->E+T):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", prod[i]);
    }

    printLR0Items();

    return 0;
}
