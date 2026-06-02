#ifndef SUDOKU_GENERATOR_HPP
#define SUDOKU_GENERATOR_HPP

#include "SudokuBoard.hpp"

class SudokuGenerator
{
public:
    SudokuBoard generate();
    
    void removeCells(
    SudokuBoard& board,
    int cellsToRemove
    );


private:
    bool fillBoard(
        SudokuBoard& board,
        int row,
        int col
    );
};

#endif