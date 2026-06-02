#include <iostream>

#include "SudokuBoard.hpp"
#include "SudokuSolver.hpp"

int main()
{
    SudokuBoard board;
    SudokuSolver solver;

    std::cout << "Original Board\n\n";

    board.printBoard();

    if(solver.solve(board))
    {
        std::cout << "\nSolved Board\n\n";

        board.printBoard();
    }

    return 0;
}