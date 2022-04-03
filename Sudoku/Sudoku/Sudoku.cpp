
#include "Sudoku.hpp"

Board solve(Board board)
{
	return board;
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