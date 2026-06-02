#include <iostream>
#include <string>

#include "SudokuBoard.hpp"
#include "SudokuSolver.hpp"
#include "SudokuGenerator.hpp"

int main(int argc, char* argv[])
{

    SudokuGenerator generator;

    SudokuBoard board = generator.generate();
    if(argc < 2)
    {
        std::cout << "Usage: sudoku <puzzle.txt>\n";
        return 1;
    }

    std::string filename = argv[1];

    //SudokuBoard board;

    try
    {
        board.loadFromFile(filename);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << "\n";
        return 1;
    }

    SudokuSolver solver;

    std::cout << "\nOriginal Board\n\n";
    board.printBoard();

    if(solver.solve(board))
    {
        std::cout << "\nSolved Board\n\n";
        board.printBoard();
    }
    else
    {
        std::cout << "No solution exists\n";
    }

    return 0;
}