#include <iostream>
#include <chrono>

#include "SudokuBoard.hpp"
#include "SudokuSolver.hpp"
#include "SolverStats.hpp"

int main()
{
    SudokuBoard board;
    SudokuSolver solver;

    std::cout << "Original Board\n\n";

    board.printBoard();

    auto start =
        std::chrono::high_resolution_clock::now();

    bool solved = solver.solve(board);

    auto end =
        std::chrono::high_resolution_clock::now();

    if(solved)
    {
        std::cout << "\nSolved Board\n\n";

        board.printBoard();

        auto duration =
            std::chrono::duration_cast
            <
                std::chrono::microseconds
            >(end - start);

        SolverStats stats = solver.getStats();

        std::cout << "\n\nStatistics\n";

        std::cout
            << "Recursive Calls: "
            << stats.recursiveCalls
            << "\n";

        std::cout
            << "Placements: "
            << stats.placements
            << "\n";

        std::cout
            << "Backtracks: "
            << stats.backtracks
            << "\n";

        std::cout
            << "Time: "
            << duration.count()
            << " microseconds\n";
    }
    else
    {
        std::cout << "\nNo solution exists.\n";
    }

    return 0;
}