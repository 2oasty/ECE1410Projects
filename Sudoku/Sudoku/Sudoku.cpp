
#include "Sudoku.hpp"

Board solve(Board board)
{
	Board boardManip = board;

	size_t row, column;

	for (row = 0; row < 9; row++)
	{
		for (column = 0; column < 9; column++)
		{
			if (board[row][column] == 0)
			{
				for (size_t n = 1; n <= 9; n++)
				{
					//if a valid number can be placed in the spot
					if (!checkRow(board, row, n) && !checkColumn(board, column, n) &&
						!checkSquare(board, row - (row % 3), column - (column % 3), n))
					{
						boardManip[row][column] = n;

						boardManip = solve(boardManip);

						if (isFull(boardManip))
						{
							return boardManip;
						}

						if (!isFull(boardManip))
						{
							boardManip[row][column] = 0;
						}
					}
				}

				return boardManip;
			}
		}
	}

	return boardManip;
}

bool checkRow(Board board, size_t row, size_t n)
{
	for (size_t column = 0; column < 9; column++)
	{
		if (board[row][column] == n)
		{
			return true;
		}
	}

	return false;
}

bool checkColumn(Board board, size_t column, size_t n)
{
	for (size_t row = 0; row < 9; row++)
	{
		if (board[row][column] == n)
		{
			return true;
		}
	}

	return false;
}

bool checkSquare(Board board, size_t boxRow, size_t boxColumn, size_t n)
{
	//Checks in a 3x3
	for (size_t row = 0; row < 3; row++)
	{
		for (size_t column = 0; column < 3; column++)
		{
			//Goes to top left corner of 3x3 and checks it 
			if (board[boxRow + row][boxColumn + column] == n)
			{
				return true;
			}
		}
	}

	return false;
}

bool isFull(Board board)
{
	for (size_t row = 0; row < 9; row++)
	{
		for (size_t column = 0; column < 9; column++)
		{
			if (board[row][column] == 0)
			{
				return false;
			}
		}
	}

	return true;
}

