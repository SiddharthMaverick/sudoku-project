#ifndef SUDOKU_SOLVER_HPP
#define SUDOKU_SOLVER_HPP

#include "SudokuBoard.hpp"

class SudokuSolver
{
public:
    bool solve(SudokuBoard& board);

private:
    bool findEmptyCell(
        SudokuBoard& board,
        int& row,
        int& col
    );

    bool isValid(
        SudokuBoard& board,
        int row,
        int col,
        int num
    );
};

#endif