#include "../include/SudokuSolver.hpp"

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
    for(int x = 0; x < 9; x++)
    {
        if(board.getCell(row, x) == num)
        {
            return false;
        }
    }

    for(int x = 0; x < 9; x++)
    {
        if(board.getCell(x, col) == num)
        {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

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

            if(solve(board))
            {
                return true;
            }

            board.setCell(row, col, 0);
        }
    }

    return false;
}

