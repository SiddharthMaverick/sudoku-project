#include "SudokuGenerator.hpp"
#include "SudokuSolver.hpp"

#include <vector>
#include <algorithm>
#include <random>


SudokuBoard SudokuGenerator::generate()
{
    Grid emptyGrid{};

    SudokuBoard board(emptyGrid);

    fillBoard(board,0,0);

    removeCells(board,40);

    return board;
}
void SudokuGenerator::removeCells(
    SudokuBoard& board,
    int cellsToRemove)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(0, 8);

    while(cellsToRemove > 0)
    {
        int row = dist(gen);
        int col = dist(gen);

        if(board.getCell(row, col) != 0)
        {
            board.setCell(row, col, 0);
            cellsToRemove--;
        }
    }
}
bool SudokuGenerator::fillBoard(
    SudokuBoard& board,
    int row,
    int col)
{
    if(row == 9)
    {
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;

    if(nextCol == 9)
    {
        nextRow++;
        nextCol = 0;
    }

    std::vector<int> nums =
    {
        1,2,3,4,5,6,7,8,9
    };

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::shuffle(
        nums.begin(),
        nums.end(),
        gen
    );

    SudokuSolver solver;

    for(int num : nums)
    {
        if(solver.isValid(board,row,col,num))
        {
            board.setCell(row,col,num);

            if(fillBoard(
                board,
                nextRow,
                nextCol))
            {
                return true;
            }

            board.setCell(row,col,0);
        }
    }

    return false;
}