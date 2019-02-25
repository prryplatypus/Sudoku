#include "sudokuChecks.h"

bool validPosition(unsigned short board[SUDOKU_SIZE][SUDOKU_SIZE], unsigned short num, unsigned short x, unsigned short y)
{
	if (validRow(board, num, y) && validColumn(board, num, x) && validDiagonalTLBR(board, num, x, y) && validDiagonalBLTR(board, num, x, y))
		return true;
	return false;
}


bool validRow(unsigned short board[SUDOKU_SIZE][SUDOKU_SIZE], unsigned short num, unsigned short y)
{
	for (unsigned short x = 0; x < SUDOKU_SIZE; ++x)
		if (board[x][y] == num)
			return false;
	return true;
}


bool validColumn(unsigned short board[SUDOKU_SIZE][SUDOKU_SIZE], unsigned short num, unsigned short x)
{
	for (unsigned short y = 0; y < SUDOKU_SIZE; ++y)
		if (board[x][y] == num)
			return false;
	return true;
}


bool validDiagonalTLBR(unsigned short board[SUDOKU_SIZE][SUDOKU_SIZE], unsigned short num, unsigned short x, unsigned short y)
{
	//Compares to start always on the furthest left and top position
	if (x < y) {
		y -= x;
		x = 0;
	}
	else {
		x -= y;
		y = 0;
	}

	for (x, y; y < SUDOKU_SIZE && x < SUDOKU_SIZE; ++x, ++y)
		if (board[x][y] == num)
			return false;

	return true;
}


bool validDiagonalBLTR(unsigned short board[SUDOKU_SIZE][SUDOKU_SIZE], unsigned short num, unsigned short x, unsigned short y)
{
	//Compares to start always on the furthest left and bottom position
	if (x < y) {
		y += x;
		x = 0;
	}
	else {
		x -= (SUDOKU_SIZE - x);
		y = SUDOKU_SIZE;
	}

	for (x, y; y < SUDOKU_SIZE && x < SUDOKU_SIZE; ++x, --y)
		if (board[x][y] == num)
			return false;

	return true;
}