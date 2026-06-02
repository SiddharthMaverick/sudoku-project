add_executable(sudoku_api src/main.cpp)

target_include_directories(sudoku_api PRIVATE
    ${PROJECT_SOURCE_DIR}/engine/include
    ${PROJECT_SOURCE_DIR}/third_party/crow
)

target_link_libraries(sudoku_api PRIVATE sudoku_engine)