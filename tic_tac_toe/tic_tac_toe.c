#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];
char current_player = 'X';

void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void display_board() {
    printf("\n");
    printf("     1   2   3\n");
    printf("   +---+---+---+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("   +---+---+---+\n");
    }
    printf("\n");
}

bool is_valid_move(int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return false;
    }
    return board[row][col] == ' ';
}

void make_move(int row, int col) {
    board[row][col] = current_player;
}

bool check_win() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == current_player && 
            board[i][1] == current_player && 
            board[i][2] == current_player) {
            return true;
        }
    }
    
    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == current_player && 
            board[1][j] == current_player && 
            board[2][j] == current_player) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] == current_player && 
        board[1][1] == current_player && 
        board[2][2] == current_player) {
        return true;
    }
    
    if (board[0][2] == current_player && 
        board[1][1] == current_player && 
        board[2][0] == current_player) {
        return true;
    }
    
    return false;
}

bool is_board_full() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switch_player() {
    current_player = (current_player == 'X') ? 'O' : 'X';
}

int main() {
    int row, col;
    bool game_over = false;
    
    printf("=================================\n");
    printf("   Welcome to Tic-Tac-Toe!\n");
    printf("=================================\n");
    printf("\nPlayer 1: X\n");
    printf("Player 2: O\n");
    printf("\nEnter row and column (1-3) to make a move.\n");
    
    init_board();
    
    while (!game_over) {
        display_board();
        
        printf("Player %c's turn\n", current_player);
        printf("Enter row (1-3): ");
        if (scanf("%d", &row) != 1) {
            // Clear input buffer on invalid input
            while (getchar() != '\n');
            printf("\nInvalid input! Please enter a number.\n");
            continue;
        }
        printf("Enter column (1-3): ");
        if (scanf("%d", &col) != 1) {
            // Clear input buffer on invalid input
            while (getchar() != '\n');
            printf("\nInvalid input! Please enter a number.\n");
            continue;
        }
        
        // Convert to 0-indexed
        row--;
        col--;
        
        if (!is_valid_move(row, col)) {
            if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
                printf("\nPosition out of bounds! Please enter numbers between 1 and 3.\n");
            } else {
                printf("\nPosition already occupied! Please choose an empty spot.\n");
            }
            continue;
        }
        
        make_move(row, col);
        
        if (check_win()) {
            display_board();
            printf("=================================\n");
            printf("   Player %c wins!\n", current_player);
            printf("=================================\n");
            game_over = true;
        } else if (is_board_full()) {
            display_board();
            printf("=================================\n");
            printf("   It's a draw!\n");
            printf("=================================\n");
            game_over = true;
        } else {
            switch_player();
        }
    }
    
    return 0;
}
