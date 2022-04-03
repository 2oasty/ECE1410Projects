
#include <gtest/gtest.h>

#include "Sudoku.hpp"

TEST(StudentWrittenTests, checkRow)
{
    Board board = { {{6, 0, 2, 3, 0, 1, 4, 0, 0},
                {0, 3, 0, 0, 0, 9, 7, 0, 0},
                {5, 0, 0, 2, 0, 7, 0, 0, 0},
                {1, 0, 0, 0, 4, 0, 2, 8, 0},
                {0, 0, 0, 0, 2, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 6, 0, 9},
                {0, 0, 3, 8, 0, 5, 9, 4, 2},
                {0, 0, 5, 6, 0, 0, 0, 3, 0},
                {0, 2, 8, 0, 0, 0, 0, 5, 0}} };
    EXPECT_EQ(checkRow(board, 0, 3), true);
    EXPECT_EQ(checkRow(board, 2, 2), true);
    EXPECT_EQ(checkRow(board, 5, 9), true);
    EXPECT_EQ(checkRow(board, 7, 4), false);
}

TEST(StudentWrittenTests, checkColumn)
{
    Board board = { {{6, 0, 2, 3, 0, 1, 4, 0, 0},
                {0, 3, 0, 0, 0, 9, 7, 0, 0},
                {5, 0, 0, 2, 0, 7, 0, 0, 0},
                {1, 0, 0, 0, 4, 0, 2, 8, 0},
                {0, 0, 0, 0, 2, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 6, 0, 9},
                {0, 0, 3, 8, 0, 5, 9, 4, 2},
                {0, 0, 5, 6, 0, 0, 0, 3, 0},
                {0, 2, 8, 0, 0, 0, 0, 5, 0}} };
    EXPECT_EQ(checkColumn(board, 0, 1), true);
    EXPECT_EQ(checkColumn(board, 2, 5), true);
    EXPECT_EQ(checkColumn(board, 5, 9), true);
    EXPECT_EQ(checkColumn(board, 7, 2), false);
}

TEST(StudentWrittenTests, checkSquare)
{
    Board board = { {{6, 0, 2, 3, 0, 1, 4, 0, 0},
                {0, 3, 0, 0, 0, 9, 7, 0, 0},
                {5, 0, 0, 2, 0, 7, 0, 0, 0},
                {1, 0, 0, 0, 4, 0, 2, 8, 0},
                {0, 0, 0, 0, 2, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 6, 0, 9},
                {0, 0, 3, 8, 0, 5, 9, 4, 2},
                {0, 0, 5, 6, 0, 0, 0, 3, 0},
                {0, 2, 8, 0, 0, 0, 0, 5, 0}} };
    EXPECT_EQ(checkSquare(board, 0, 0, 5), true);
    EXPECT_EQ(checkSquare(board, 0, 6, 4), true);
    EXPECT_EQ(checkSquare(board, 3, 6, 6), true);
    EXPECT_EQ(checkSquare(board, 6, 3, 1), false);
}