#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int countNeighbors(int board[][MAX_COLS], int row, int col);
void displayBoard(int board[][MAX_COLS]);
void lifeGame(int board[][MAX_COLS]);

int main() {
    srand(time(0));
    int board[MAX_ROWS][MAX_COLS];

    // Initialize the game board with random live or dead cells
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }

    lifeGame(board);
    return 0;
}

int countNeighbors(int board[][MAX_COLS], int row, int col) {
    int count = 0;

    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < MAX_ROWS && j >= 0 && j < MAX_COLS) {
                count += board[i][j];
            }
        }
    }

    // Subtract the cell itself to get the count of live neighbors
    count -= board[row][col];

    return count;
}

void displayBoard(int board[][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void lifeGame(int board[][MAX_COLS]) {
    int newBoard[MAX_ROWS][MAX_COLS];

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            int neighbors = countNeighbors(board, i, j);

            // Apply the rules of the game
            if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                newBoard[i][j] = 0;
            } else if (board[i][j] == 0 && neighbors == 3) {
                newBoard[i][j] = 1;
            } else {
                newBoard[i][j] = board[i][j];
            }
        }
    }

    printf("Initial game board:\n");
    displayBoard(board);

    printf("Updated game board:\n");
    displayBoard(newBoard);
}