#include <iostream>

#include "SudokuBoard.hpp"
#include "SudokuGenerator.hpp"

int main()
{
    SudokuGenerator generator;

    SudokuBoard board =
        generator.generate();

    board.printBoard();

    return 0;
}