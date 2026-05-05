#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[10][20];
char nonTerminals[10], terminals[10];
int prodCount, ntCount = 0, tCount = 0;
char table[10][10][20];

int isTerminal(char c) {
    return !isupper(c) && c != 'e';
}

int findIndex(char arr[], int size, char c) {
    for (int i = 0; i < size; i++)
        if (arr[i] == c)
            return i;
    return -1;
}

void addTerminal(char c) {
    if (findIndex(terminals, tCount, c) == -1)
        terminals[tCount++] = c;
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &prodCount);

    printf("Enter productions (Example: E->TX):\n");
    for (int i = 0; i < prodCount; i++) {
        scanf("%s", prod[i]);
        nonTerminals[ntCount++] = prod[i][0];
    }

    for (int i = 0; i < prodCount; i++) {
        for (int j = 3; j < strlen(prod[i]); j++) {
            if (isTerminal(prod[i][j]))
                addTerminal(prod[i][j]);
        }
    }
    addTerminal('$');

    for (int i = 0; i < ntCount; i++)
        for (int j = 0; j < tCount; j++)
            strcpy(table[i][j], "-");

    for (int i = 0; i < prodCount; i++) {
        int row = findIndex(nonTerminals, ntCount, prod[i][0]);
        char firstSymbol = prod[i][3];
        int col = findIndex(terminals, tCount, firstSymbol);

        if (col != -1)
            strcpy(table[row][col], prod[i]);
    }

    printf("\nPredictive Parsing Table:\n\t");
    for (int i = 0; i < tCount; i++)
        printf("%c\t", terminals[i]);
    printf("\n");

    for (int i = 0; i < ntCount; i++) {
        printf("%c\t", nonTerminals[i]);
        for (int j = 0; j < tCount; j++)
            printf("%s\t", table[i][j]);
        printf("\n");
    }

    return 0;
}
