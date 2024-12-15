#include "game_logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Cell **create_board(int rows, int cols) {

  Cell **board = (Cell **)malloc(rows * sizeof(Cell *));
  if (!board) {
    printf("Memory allocation failded! \n");
    exit(1);
  }

  for (int i = 0; i < rows; i++) {
    board[i] = (Cell *)malloc(cols * sizeof(Cell));
    if (!board) {
      printf("Memory allocation failed! \n");
      exit(1);
    }
  }
  return board;
}

void free_board(Cell **board, int rows) {
  for (int i = 0; i < rows; i++) {
    free(board[i]);
  }
  free(board);
}

void init_board(Cell **board, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      board[i][j].is_mine = 0;
      board[i][j].is_reveal = 0;
      board[i][j].is_flagged = 0;
      board[i][j].adjacent_mines = 0;
    }
  }
}

void a_mines(Cell **board, int rows, int cols, int mines) {
  int placed = 0;
  srand(time(NULL));
  while (placed < mines) {
    int row = rand() % rows;
    int col = rand() % cols;

    if (!board[row][col].is_mine) {
      board[row][col].is_mine = 1;
      placed++;
    }
  }
}

void find_adjacent_mines(Cell **board, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (board[i][j].is_mine) {
        continue;
      }

      int count = 0;

      for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
          int ni = i + di;
          int nj = j + dj;

          if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
            if (board[ni][nj].is_mine) {
              count++;
            }
          }
        }
      }
      board[i][j].adjacent_mines = count;
    }
  }
}

void print_board(Cell **board, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (board[i][j].is_mine) {
        printf("* ");
      } else {
        printf("%d ", board[i][j].adjacent_mines);
      }
    }
    printf("\n");
  }
  printf("\n");
}
