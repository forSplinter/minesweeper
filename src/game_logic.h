#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#define ROWS 9
#define COLS 9
#define MINES 10

typedef struct {
  int is_mine;
  int is_reveal;
  int is_flagged;
  int adjacent_mines;
} Cell;

Cell **create_board(int rows, int cols);
void init_board(Cell **board, int rows, int cols);
void a_mines(Cell **board, int rows, int cols, int mines);
void find_adjacent_mines(Cell **board, int rows, int cols);
void print_board(Cell **board, int rows, int cols);
void free_board(Cell **board, int rows);

#endif // !GAME_LOGIC_H
