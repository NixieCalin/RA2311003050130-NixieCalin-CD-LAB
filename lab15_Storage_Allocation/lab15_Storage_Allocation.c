#include <stdio.h>

int main() {
    int stack[10];
    int top = -1;
    int choice, value;

    while (1) {
        printf("\nStack Allocation Menu");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (top == 9) {
                    printf("Stack Overflow\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    stack[++top] = value;
                    printf("Value pushed into stack\n");
                }
                break;

            case 2:
                if (top == -1) {
                    printf("Stack Underflow\n");
                } else {
                    printf("Popped value: %d\n", stack[top--]);
                }
                break;

            case 3:
                if (top == -1) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack contents: ");
                    for (int i = top; i >= 0; i--) {
                        printf("%d ", stack[i]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
