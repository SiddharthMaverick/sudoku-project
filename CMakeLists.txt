cmake_minimum_required(VERSION 3.20)

project(SudokuSolver)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(engine)
add_subdirectory(apps/sudoku-cli)