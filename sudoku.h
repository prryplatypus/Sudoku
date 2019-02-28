#pragma once

#define BOARD_SIZE 9
#define START_VALUE -1


//Resuelve el Sudoku
//@Require	param1 must have solution
//@Param	int[][]		Tabla de Sudoku
void resolverSudoku(int sudoku[BOARD_SIZE][BOARD_SIZE]);

//Checks if any empty cells left
//@Param	int[][]		Tabla de Sudoku
//@Returns	bool		true if empty cells left
bool quedanVacias(int sudoku[BOARD_SIZE][BOARD_SIZE]);

//Imprime el tablero de sudoku
//@Param	int[][]		Tabla de Sudoku
void mostrarSudoku(int sudoku[BOARD_SIZE][BOARD_SIZE]);

//Codigo proporcionado en ejercicio
//@Param	int[][]		Tabla de Sudoku
//@Param	int			Fila
//@Param	int			Columna
//@Param	int			Valor
//@Returns	bool		true if valid position for number
bool esValido(int sudoku[BOARD_SIZE][BOARD_SIZE], int fila, int columna, int valor);