Lab 1 – Implementation of Lexical Analyzer
## Aim
To implement a lexical analyzer that identifies keywords, identifiers, operators, numbers, and special symbols from a given input program.

## Algorithm
1. Read input character by character.
2. If the character is a letter, collect characters to form a word.
3. Check whether the word is a keyword or identifier.
4. If the character is a digit, recognize it as a number.
5. If the character matches an operator or special symbol, print it.
6. Repeat until end of file.

## How to Compile
gcc lexical_analyzer.c -o lab1

## How to Run
./lab01_Lexical_Analyzer
