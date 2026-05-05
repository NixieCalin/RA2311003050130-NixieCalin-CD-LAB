# Lab 14 – Implementation of Global Data Flow Analysis

## Aim
To implement Global Data Flow Analysis using Reaching Definitions technique.

## Algorithm
1. Read the number of basic blocks.
2. Read GEN and KILL sets for each block.
3. Initialize IN and OUT sets.
4. Compute IN and OUT sets using data flow equations.
5. Display the result.

## How to Compile
gcc lab14_Global_Data_Flow_Analysis.c -o lab14

## How to Run
./lab14

## Output
Displays GEN, KILL, IN, and OUT sets for each basic block.
