#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n;
char prod[10][10], first[10][10], follow[10][10];
char nt[10];
int firstCount[10], followCount[10];

void addToSet(char set[], int *count, char value) {
    for (int i = 0; i < *count; i++)
        if (set[i] == value)
            return;
    set[(*count)++] = value;
}

void findFirst(int i) {
    for (int j = 3; j < strlen(prod[i]); j++) {
        if (!isupper(prod[i][j])) {
            addToSet(first[i], &firstCount[i], prod[i][j]);
            break;
        } else {
            for (int k = 0; k < n; k++) {
                if (nt[k] == prod[i][j]) {
                    findFirst(k);
                    for (int m = 0; m < firstCount[k]; m++)
                        addToSet(first[i], &firstCount[i], first[k][m]);
                }
            }
            break;
        }
    }
}

void findFollow(int i) {
    if (i == 0)
        addToSet(follow[i], &followCount[i], '$');

    for (int j = 0; j < n; j++) {
        for (int k = 3; k < strlen(prod[j]); k++) {
            if (prod[j][k] == nt[i]) {
                if (prod[j][k + 1] != '\0') {
                    if (!isupper(prod[j][k + 1]))
                        addToSet(follow[i], &followCount[i], prod[j][k + 1]);
                    else {
                        for (int m = 0; m < n; m++) {
                            if (nt[m] == prod[j][k + 1]) {
                                for (int p = 0; p < firstCount[m]; p++)
                                    addToSet(follow[i], &followCount[i], first[m][p]);
                            }
                        }
                    }
                } else {
                    for (int m = 0; m < followCount[j]; m++)
                        addToSet(follow[i], &followCount[i], follow[j][m]);
                }
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
        nt[i] = prod[i][0];
        firstCount[i] = followCount[i] = 0;
    }

    for (int i = 0; i < n; i++)
        findFirst(i);

    for (int i = 0; i < n; i++)
        findFollow(i);

    printf("\nFIRST sets:\n");
    for (int i = 0; i < n; i++) {
        printf("FIRST(%c) = { ", nt[i]);
        for (int j = 0; j < firstCount[i]; j++)
            printf("%c ", first[i][j]);
        printf("}\n");
    }

    printf("\nFOLLOW sets:\n");
    for (int i = 0; i < n; i++) {
        printf("FOLLOW(%c) = { ", nt[i]);
        for (int j = 0; j < followCount[i]; j++)
            printf("%c ", follow[i][j]);
        printf("}\n");
    }

    return 0;
}
