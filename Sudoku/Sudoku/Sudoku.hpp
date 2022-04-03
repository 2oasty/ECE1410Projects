#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <array>

const size_t SIZE = 9;

typedef std::array<std::array<size_t, SIZE>, SIZE> Board;

Board solve(Board board);

bool checkRow(Board board, size_t row, size_t n);

bool checkColumn(Board board, size_t column, size_t n);

bool checkSquare(Board board, size_t boxRow, size_t boxColumn, size_t n);

bool isFull(Board board);

#endif