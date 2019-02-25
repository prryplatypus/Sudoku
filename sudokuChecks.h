#pragma once
#define SUDOKU_SIZE 9

//Function to check if the position is valid (calls all of the following functions)
bool validPosition(unsigned short board[SUDOKU_SIZE][SUDOKU_SIZE], unsigned short num, unsigned short x, unsigned short y);

//Checks if the given num can be used in the given row of the board
bool validRow(unsigned short board[SUDOKU_SIZE][SUDOKU_SIZE], unsigned short num, unsigned short y);

//Checks if the given num can be used in the given column of the board
bool validColumn(unsigned short board[SUDOKU_SIZE][SUDOKU_SIZE], unsigned short num, unsigned short x);

//Checks if the given num can be used in the diagonal top-left to bottom-right relative to the given position
bool validDiagonalTLBR(unsigned short board[SUDOKU_SIZE][SUDOKU_SIZE], unsigned short num, unsigned short x, unsigned short y);

//Checks if the given num can be used in the diagonal bottom-left to top-right relative to the given position
bool validDiagonalBLTR(unsigned short board[SUDOKU_SIZE][SUDOKU_SIZE], unsigned short num, unsigned short x, unsigned short y);