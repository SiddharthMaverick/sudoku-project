#include <cassert>
#include <stdexcept>

#include "SudokuBoard.hpp"

int main()
{
    SudokuBoard board;

    bool exceptionThrown = false;

    try
    {
        board.getCell(100, 0);
    }
    catch(const std::out_of_range&)
    {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    return 0;
}