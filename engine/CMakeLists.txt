add_library(
    sudoku_engine

    src/SudokuBoard.cpp
    src/SudokuSolver.cpp
)

target_include_directories(
    sudoku_engine
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)