cmake_minimum_required(VERSION 3.20)

project(SudokuSolver)

set(CMAKE_CXX_STANDARD 17)

add_library(
    sudoku_engine

    src/SudokuBoard.cpp
    src/SudokuSolver.cpp
)

target_include_directories(
    sudoku_engine

    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(
    sudoku

    src/main.cpp
)

target_link_libraries(
    sudoku

    PRIVATE
    sudoku_engine
)

enable_testing()

add_executable(
    sudoku_tests
    tests/test_solver.cpp
)

target_link_libraries(
    sudoku_tests
    PRIVATE
    sudoku_engine
)

add_test(
    NAME SudokuSolverTest
    COMMAND sudoku_tests
)

add_executable(
    board_tests
    tests/test_board.cpp
)

target_link_libraries(
    board_tests
    PRIVATE
    sudoku_engine
)

add_test(
    NAME BoardBoundsTest
    COMMAND board_tests
)