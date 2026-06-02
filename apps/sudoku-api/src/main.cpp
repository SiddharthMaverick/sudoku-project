#include "crow.h"
#include "SudokuBoard.hpp"
#include "SudokuGenerator.hpp"
#include "SudokuSolver.hpp"
#include <iostream>

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/api/generate")([](){
        SudokuGenerator generator;
        SudokuBoard board = generator.generate();
        
        crow::json::wvalue x;
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                x["board"][r][c] = board.getCell(r, c);
            }
        }
        return x;
    });

    CROW_ROUTE(app, "/api/solve").methods(crow::HTTPMethod::Post)([](const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x) return crow::response(400);

        SudokuBoard board;
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (x.has("board") && x["board"][r].size() > c) {
                    board.setCell(r, c, x["board"][r][c].i());
                } else {
                    return crow::response(400, "Invalid JSON format");
                }
            }
        }

        SudokuSolver solver;
        if (solver.solve(board)) {
            crow::json::wvalue result;
            for (int r = 0; r < 9; ++r) {
                for (int c = 0; c < 9; ++c) {
                    result["board"][r][c] = board.getCell(r, c);
                }
            }
            return crow::response(result);
        } else {
            return crow::response(400, "Unsolvable board");
        }
    });

    app.port(8080).multithreaded().run();

    return 0;
}