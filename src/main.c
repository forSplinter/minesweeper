#include "game_logic.h"
#include <stdio.h>

int main() {
  Cell **board = create_board(ROWS, COLS);

  init_board(board, ROWS, COLS);

  a_mines(board, ROWS, COLS, MINES);

  find_adjacent_mines(board, ROWS, COLS);

  printf("Plateau (Vue Débogage) :\n");

  print_board(board, ROWS, COLS);

  free_board(board, ROWS);

  return 0;
}
