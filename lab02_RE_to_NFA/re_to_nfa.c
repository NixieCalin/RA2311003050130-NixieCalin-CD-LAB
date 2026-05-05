#include <stdio.h>
#include <string.h>

int state = 0;

/* Function to print NFA transition */
void addTransition(int from, char symbol, int to) {
    if (symbol == 'e')
        printf("q%d -- ε --> q%d\n", from, to);
    else
        printf("q%d -- %c --> q%d\n", from, symbol, to);
}

int main() {
    char re[50];
    int i;
    int start, current, next;

    printf("Enter Regular Expression: ");
    scanf("%s", re);

    start = state++;
    current = start;

    for (i = 0; i < strlen(re); i++) {

        /* Kleene Star */
        if (re[i] == '*') {
            addTransition(current, 'e', current);
        }

        /* Union (simple handling) */
        else if (re[i] == '|') {
            next = state++;
            addTransition(start, 'e', next);
            current = next;
        }

        /* Symbol transition */
        else {
            next = state++;
            addTransition(current, re[i], next);
            current = next;
        }
    }

    printf("Start State : q%d\n", start);
    printf("Final State : q%d\n", current);

    return 0;
}
