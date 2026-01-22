# Tic-Tac-Toe Game

A simple command-line tic-tac-toe game written in C.

## Features

- Two-player game (Player X vs Player O)
- 3x3 game board
- Input validation
- Win detection (rows, columns, diagonals)
- Draw detection

## Building

To compile the game, run:

```bash
make
```

Or compile manually:

```bash
gcc -Wall -Wextra -std=c99 -o tic_tac_toe tic_tac_toe.c
```

## Running

To run the game:

```bash
./tic_tac_toe
```

Or use the Makefile:

```bash
make run
```

## How to Play

1. The game is played on a 3x3 grid
2. Players take turns placing their mark (X or O)
3. Enter the row number (1-3) and column number (1-3) when prompted
4. The first player to get 3 of their marks in a row (horizontally, vertically, or diagonally) wins
5. If all 9 squares are filled and no player has won, the game is a draw

## Cleaning

To remove the compiled executable:

```bash
make clean
```
