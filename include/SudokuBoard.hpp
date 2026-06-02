#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP
#include <array>
using Grid = std::array<std::array<int, 9>, 9>;
class SudokuBoard
{
private:
    Grid board;

public:
    SudokuBoard();
    SudokuBoard(const Grid& initialBoard);
    void printBoard();
    void loadBoard(const Grid& newBoard);
    const Grid& getGrid() const;
    int getCell(int row, int col);

    void setCell(int row, int col, int value);
};

#endif