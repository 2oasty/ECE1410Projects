#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <array>

const size_t SIZE = 9;

typedef std::array<std::array<size_t, SIZE>, SIZE> Board;

Board solve(Board board);

#endif