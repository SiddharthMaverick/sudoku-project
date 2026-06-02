#ifndef SUDOKU_SOLVER_HPP
#define SUDOKU_SOLVER_HPP

#include "SudokuBoard.hpp"
#include "SolverStats.hpp"

class SudokuSolver
{
public:
    bool solve(SudokuBoard& board);

    SolverStats getStats() const;

    bool isValid(
        SudokuBoard& board,
        int row,
        int col,
        int num
    );

private:
    SolverStats stats;

    bool findEmptyCell(
        SudokuBoard& board,
        int& row,
        int& col
    );


};

#endif