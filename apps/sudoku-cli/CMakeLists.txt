add_executable(
    sudoku
    src/main.cpp
)

target_link_libraries(
    sudoku
    PRIVATE
    sudoku_engine
)