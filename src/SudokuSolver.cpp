#include "SudokuSolver.hpp"

bool SudokuSolver::findEmptyCell(
    SudokuBoard& board,
    int& row,
    int& col)
{
    for(row = 0; row < 9; row++)
    {
        for(col = 0; col < 9; col++)
        {
            if(board.getCell(row, col) == 0)
            {
                return true;
            }
        }
    }

    return false;
}

bool SudokuSolver::isValid(
    SudokuBoard& board,
    int row,
    int col,
    int num)
{
    // Check row
    for(int x = 0; x < 9; x++)
    {
        if(board.getCell(row, x) == num)
        {
            return false;
        }
    }

    // Check column
    for(int x = 0; x < 9; x++)
    {
        if(board.getCell(x, col) == num)
        {
            return false;
        }
    }

    // Check 3x3 box
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board.getCell(startRow + i,
                             startCol + j) == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool SudokuSolver::solve(SudokuBoard& board)
{
    stats.recursiveCalls++;

    int row;
    int col;

    if(!findEmptyCell(board, row, col))
    {
        return true;
    }

    for(int num = 1; num <= 9; num++)
    {
        if(isValid(board, row, col, num))
        {
            board.setCell(row, col, num);

            stats.placements++;

            if(solve(board))
            {
                return true;
            }

            stats.backtracks++;

            board.setCell(row, col, 0);
        }
    }

    return false;
}

SolverStats SudokuSolver::getStats() const
{
    return stats;
}