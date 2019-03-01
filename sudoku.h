#pragma once

#define BOARD_SIZE 9
#define START_VALUE -1

class Sudoku {
private:
	int tablero[BOARD_SIZE][BOARD_SIZE];

	//Codigo proporcionado en ejercicio
	//@Param	int[][]		Tabla de Sudoku
	//@Param	int			Fila
	//@Param	int			Columna
	//@Param	int			Valor
	//@Returns	bool		true if valid position for number
	bool esValido(int fila, int columna, int valor);

public:
	//Constructor
	//@Param1	int[][]		Sudoku Board
	Sudoku(int sudoku[BOARD_SIZE][BOARD_SIZE]);

	//Destructor
	~Sudoku();

	//Resuelve el Sudoku
	//@Requires				must have solution
	void resolver();

	//Checks if any empty cells left
	//@Returns	bool		true if empty cells left
	bool quedanVacias();

	//Imprime el tablero de sudoku
	void mostrar();
};