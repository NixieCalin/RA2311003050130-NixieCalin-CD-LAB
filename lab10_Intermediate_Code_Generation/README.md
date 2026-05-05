# Lab 10 – Intermediate Code Generation (Postfix and Prefix)

## Aim
To generate intermediate code by converting a given infix expression into postfix and prefix expressions.

## Algorithm
1. Read the infix expression from the user.
2. Convert the infix expression into postfix notation using stack operations.
3. Reverse the infix expression and replace '(' with ')' and vice versa.
4. Convert the modified expression into postfix.
5. Reverse the postfix expression to obtain the prefix expression.
6. Display the postfix and prefix expressions.

## How to Compile
gcc lab10_Intermediate_Code_Generation.c -o lab10

## How to Run
./lab10

## Output
Displays the postfix and prefix expressions for the given infix expression.
