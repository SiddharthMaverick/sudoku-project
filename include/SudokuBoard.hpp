#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP

class SudokuBoard
{
private:
    int board[9][9];

public:
    SudokuBoard();

    void printBoard();

    int getCell(int row, int col);

    void setCell(int row, int col, int value);
};

#endif