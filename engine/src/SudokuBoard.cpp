#include<iostream>
#include "SudokuBoard.hpp"
#include <stdexcept>

SudokuBoard::SudokuBoard()
{
    board =
    {{
        {{5,3,0,0,7,0,0,0,0}},
        {{6,0,0,1,9,5,0,0,0}},
        {{0,9,8,0,0,0,0,6,0}},
        {{8,0,0,0,6,0,0,0,3}},
        {{4,0,0,8,0,3,0,0,1}},
        {{7,0,0,0,2,0,0,0,6}},
        {{0,6,0,0,0,0,2,8,0}},
        {{0,0,0,4,1,9,0,0,5}},
        {{0,0,0,0,8,0,0,7,9}}
    }};
}
SudokuBoard::SudokuBoard(const Grid& initialBoard): board(initialBoard)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            board[i][j] = initialBoard[i][j];
        }
    }
}
const Grid& SudokuBoard::getGrid() const
{
    return board;
}
void SudokuBoard::loadBoard(const Grid& newBoard)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            board[i][j] = newBoard[i][j];
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
    if(row < 0 || row >= 9)
    {
        throw std::out_of_range("Invalid row");
    }

    if(col < 0 || col >= 9)
    {
        throw std::out_of_range("Invalid column");
    }

    return board[row][col];
}

void SudokuBoard::setCell(
    int row,
    int col,
    int value)
{
    if(row < 0 || row >= 9)
    {
        throw std::out_of_range("Invalid row");
    }

    if(col < 0 || col >= 9)
    {
        throw std::out_of_range("Invalid column");
    }

    if(value < 0 || value > 9)
    {
        throw std::out_of_range("Invalid value");
    }

    board[row][col] = value;
}


