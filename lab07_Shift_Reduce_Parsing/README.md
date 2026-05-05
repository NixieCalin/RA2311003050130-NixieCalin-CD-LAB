# Lab 07 – Shift Reduce Parsing

## Aim
To implement Shift Reduce Parsing for a given grammar.

## Grammar Used
E → E + E  
E → E * E  
E → i  

## Algorithm
1. Initialize stack and input buffer.
2. Perform shift operation by pushing symbols onto stack.
3. Check for possible reductions using grammar rules.
4. Reduce stack symbols to non-terminal.
5. Accept if stack contains start symbol and input is exhausted.

## How to Compile
gcc lab07_Shift_Reduce.c -o lab7

## How to Run
./lab7

## Output
Displays shift and reduce operations and acceptance result.
