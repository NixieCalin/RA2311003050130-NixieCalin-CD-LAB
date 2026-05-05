#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = -1, ip = 0;

void shift() {
    stack[++top] = input[ip++];
    stack[top + 1] = '\0';
    printf("SHIFT\t\t%s\t\t%s\n", stack, input + ip);
}

int reduce() {
    // Example grammar:
    // E -> E+E
    // E -> E*E
    // E -> i

    if (top >= 0 && stack[top] == 'i') {
        stack[top] = 'E';
        printf("REDUCE E->i\t%s\t\t%s\n", stack, input + ip);
        return 1;
    }

    if (top >= 2 &&
        stack[top] == 'E' &&
        stack[top - 1] == '+' &&
        stack[top - 2] == 'E') {
        top -= 2;
        stack[top] = 'E';
        printf("REDUCE E->E+E\t%s\t\t%s\n", stack, input + ip);
        return 1;
    }

    if (top >= 2 &&
        stack[top] == 'E' &&
        stack[top - 1] == '*' &&
        stack[top - 2] == 'E') {
        top -= 2;
        stack[top] = 'E';
        printf("REDUCE E->E*E\t%s\t\t%s\n", stack, input + ip);
        return 1;
    }

    return 0;
}

int main() {
    printf("Enter input string (end with $): ");
    scanf("%s", input);

    printf("\nSTACK\t\tINPUT\n");
    printf("-----\t\t-----\n");

    while (1) {
        if (ip < strlen(input) && input[ip] != '$') {
            shift();
        }

        while (reduce());

        if (stack[0] == 'E' && top == 0 && input[ip] == '$') {
            printf("\nString Accepted \n");
            break;
        }

        if (ip >= strlen(input)) {
            printf("\nString Rejected \n");
            break;
        }
    }

    return 0;
}
