#include "SudokuService.hpp"
#include "SudokuSolver.hpp"

bool SudokuService::solvePuzzle(SudokuBoard& board)
{
    SudokuSolver solver;

    return solver.solve(board);
}