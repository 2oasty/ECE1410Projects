
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

TEST(StudentWrittenTests, expertSudoku)
{
    Board board = { {{0, 6, 1, 0, 0, 5, 0, 0, 0},
                {0, 0, 0, 0, 0, 4, 0, 2, 0},
                {0, 0, 0, 0, 9, 0, 0, 0, 6},
                {0, 0, 0, 0, 0, 0, 8, 7, 2},
                {5, 0, 9, 0, 0, 0, 4, 0, 0},
                {0, 0, 3, 0, 0, 0, 9, 0, 0},
                {7, 0, 0, 0, 0, 0, 0, 0, 0},
                {8, 0, 0, 2, 0, 0, 0, 0, 4},
                {0, 9, 0, 8, 7, 0, 0, 0, 0}} };
    Board response = solve(board);

    Board answer = { {{4, 6, 1, 7, 2, 5, 3, 8, 9},
                {9, 5, 8, 3, 6, 4, 1, 2, 7},
                {3, 2, 7, 1, 9, 8, 5, 4, 6},
                {1, 4, 6, 9, 5, 3, 8, 7, 2},
                {5, 7, 9, 6, 8, 2, 4, 3, 1},
                {2, 8, 3, 4, 1, 7, 9, 6, 5},
                {7, 3, 2, 5, 4, 9, 6, 1, 8},
                {8, 1, 5, 2, 3, 6, 7, 9, 4},
                {6, 9, 4, 8, 7, 1, 2, 5, 3}} };
    EXPECT_EQ(response, answer);
}

TEST(StudentWrittenTests, evilSudoku)
{
    Board board = { {{0, 0, 0, 8, 0, 0, 1, 0, 0},
                {0, 0, 7, 0, 1, 6, 0, 0, 3},
                {0, 6, 0, 4, 0, 0, 0, 0, 0},
                {5, 0, 0, 0, 0, 0, 0, 0, 4},
                {0, 2, 0, 0, 7, 1, 5, 0, 0},
                {0, 0, 0, 0, 8, 0, 0, 0, 0},
                {0, 7, 0, 0, 5, 2, 4, 0, 0},
                {0, 0, 3, 0, 0, 0, 0, 9, 0},
                {0, 0, 0, 6, 0, 0, 0, 0, 0}} };
    Board response = solve(board);

    Board answer = { {{3, 9, 5, 8, 2, 7, 1, 4, 6},
                {2, 4, 7, 9, 1, 6, 8, 5, 3},
                {8, 6, 1, 4, 3, 5, 9, 2, 7},
                {5, 1, 8, 2, 6, 9, 3, 7, 4},
                {6, 2, 4, 3, 7, 1, 5, 8, 9},
                {7, 3, 9, 5, 8, 4, 2, 6, 1},
                {9, 7, 6, 1, 5, 2, 4, 3, 8},
                {1, 5, 3, 7, 4, 8, 6, 9, 2},
                {4, 8, 2, 6, 9, 3, 7, 1, 5}} };
    EXPECT_EQ(response, answer);
}