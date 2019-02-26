#include <iostream>

#include "sudokuChecks.h"

int main() {
	//Empty fields should be set to 0
	unsigned short board[SUDOKU_SIZE][SUDOKU_SIZE] =
	{
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	if (validPosition(board, 5, 0, 0))
		std::cout << "Valid";

	return 0;
}