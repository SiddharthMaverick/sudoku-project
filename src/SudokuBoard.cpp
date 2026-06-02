#include<iostream>
#include "SudokuBoard.hpp"

SudokuBoard::SudokuBoard()
{
    int initialBoard[9][9] =
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            board[i][j] = initialBoard[i][j];
        }
    }
}
SudokuBoard::SudokuBoard(int initialBoard[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            board[i][j] = initialBoard[i][j];
        }
    }
}

void SudokuBoard::printBoard()
{
    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            std::cout << board[row][col] << " ";
        }

        std::cout << "\n";
    }
}

int SudokuBoard::getCell(int row, int col)
{
    return board[row][col];
}

void SudokuBoard::setCell(int row, int col, int value)
{
    board[row][col] = value;
}


