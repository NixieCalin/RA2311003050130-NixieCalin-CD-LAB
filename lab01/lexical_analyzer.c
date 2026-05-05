#include <stdio.h>
#include <ctype.h>
#include <string.h>

char keywords[10][10] = {
    "int", "float", "if", "else", "return", "while", "for", "char", "double", "void"
};

int isKeyword(char word[]) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(keywords[i], word) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[50];
    int i = 0;

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {

        // Identifier or Keyword
        if (isalpha(ch)) {
            buffer[i++] = ch;
            while (isalnum(ch = fgetc(fp))) {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';
            i = 0;
            fseek(fp, -1, SEEK_CUR);

            if (isKeyword(buffer))
                printf("Keyword : %s\n", buffer);
            else
                printf("Identifier : %s\n", buffer);
        }

        // Number
        else if (isdigit(ch)) {
            buffer[i++] = ch;
            while (isdigit(ch = fgetc(fp))) {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';
            i = 0;
            fseek(fp, -1, SEEK_CUR);
            printf("Number : %s\n", buffer);
        }

        // Operators
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
                 ch == '=' || ch == '>' || ch == '<') {
            printf("Operator : %c\n", ch);
        }

        // Special Symbols
        else if (ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
                 ch == ';' || ch == ',') {
            printf("Special Symbol : %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}
