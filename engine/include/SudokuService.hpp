#ifndef SUDOKU_SERVICE_HPP
#define SUDOKU_SERVICE_HPP

#include "SudokuBoard.hpp"

class SudokuService
{
public:
    bool solvePuzzle(SudokuBoard& board);
};

#endif