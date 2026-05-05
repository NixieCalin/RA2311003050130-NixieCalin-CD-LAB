#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[10][20];
char leading[10][10], trailing[10][10];
char nonTerminals[10];
int n;
int leadCount[10], trailCount[10];

void add(char set[], int *count, char symbol) {
    for (int i = 0; i < *count; i++)
        if (set[i] == symbol)
            return;
    set[(*count)++] = symbol;
}

void findLeading(int i) {
    char *rhs = strchr(prod[i], '>') + 1;

    if (!isupper(rhs[0])) {
        add(leading[i], &leadCount[i], rhs[0]);
    } else {
        for (int j = 0; j < n; j++) {
            if (nonTerminals[j] == rhs[0]) {
                findLeading(j);
                for (int k = 0; k < leadCount[j]; k++)
                    add(leading[i], &leadCount[i], leading[j][k]);
            }
        }
    }
}

void findTrailing(int i) {
    int len = strlen(prod[i]);
    char last = prod[i][len - 1];

    if (!isupper(last)) {
        add(trailing[i], &trailCount[i], last);
    } else {
        for (int j = 0; j < n; j++) {
            if (nonTerminals[j] == last) {
                findTrailing(j);
                for (int k = 0; k < trailCount[j]; k++)
                    add(trailing[i], &trailCount[i], trailing[j][k]);
            }
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: E->E+T):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", prod[i]);
        nonTerminals[i] = prod[i][0];
        leadCount[i] = trailCount[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        findLeading(i);
        findTrailing(i);
    }

    printf("\nLEADING sets:\n");
    for (int i = 0; i < n; i++) {
        printf("LEADING(%c) = { ", nonTerminals[i]);
        for (int j = 0; j < leadCount[i]; j++)
            printf("%c ", leading[i][j]);
        printf("}\n");
    }

    printf("\nTRAILING sets:\n");
    for (int i = 0; i < n; i++) {
        printf("TRAILING(%c) = { ", nonTerminals[i]);
        for (int j = 0; j < trailCount[i]; j++)
            printf("%c ", trailing[i][j]);
        printf("}\n");
    }

    return 0;
}
