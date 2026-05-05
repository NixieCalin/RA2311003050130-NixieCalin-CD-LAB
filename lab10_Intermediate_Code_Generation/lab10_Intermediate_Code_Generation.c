#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[50];
int top = -1;

/* Stack operations */
void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

/* Operator precedence */
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

/* Infix to Postfix conversion */
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop();
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

/* Reverse string */
void reverse(char exp[]) {
    int i, j;
    char temp;
    int len = strlen(exp);

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

/* Infix to Prefix conversion */
void infixToPrefix(char infix[], char prefix[]) {
    char revInfix[50], postfix[50];
    int i;

    strcpy(revInfix, infix);
    reverse(revInfix);

    for (i = 0; revInfix[i] != '\0'; i++) {
        if (revInfix[i] == '(')
            revInfix[i] = ')';
        else if (revInfix[i] == ')')
            revInfix[i] = '(';
    }

    top = -1;
    infixToPostfix(revInfix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[50], postfix[50], prefix[50];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    top = -1;
    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    printf("Postfix Expression: %s\n", postfix);
    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
