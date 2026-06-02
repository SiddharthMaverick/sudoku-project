#ifndef SUDOKU_SOLVER_HPP
#define SUDOKU_SOLVER_HPP

#include "SudokuBoard.hpp"
#include "SolverStats.hpp"

class SudokuSolver
{
public:
    bool solve(SudokuBoard& board);

    SolverStats getStats() const;

private:
    SolverStats stats;

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