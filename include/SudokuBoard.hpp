#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP
#include <array>
class SudokuBoard
{
private:
    

    using Grid = std::array<std::array<int, 9>, 9>;

    Grid board;

public:
    SudokuBoard();
    SudokuBoard(int initialBoard[9][9]);
    void printBoard();
    void loadBoard(int newBoard[9][9]);

    int getCell(int row, int col);

    void setCell(int row, int col, int value);
};

#endif