#include <iostream>

#include "sudoku.h"

void resolverSudoku(int sudoku[BOARD_SIZE][BOARD_SIZE])
{
	int x = -1, y = -1;

	//Busca las 'coordenadas' de las que la correspondiente llamada
	//a la función se va a encargar
	for (int i = 0; i < BOARD_SIZE && x == -1; ++i)
		for (int j = 0; j < BOARD_SIZE && y == -1; ++j)
			if (sudoku[i][j] == START_VALUE) {//Comprueba que esté vacía la casilla (quitado de función 'esValido')
				x = i;
				y = j;					
			}
	//Si ya no quedan filas, se ha completado correctamente
	if (x == -1)
		return;

	//Prueba todos los numeros posibles hasta encontrar uno válido
	//Además, todos los siguientes deben serlo también. De no ser así,
	//prueba con el siguiente número. Si no vale ninguna combinación, vuelve a la llamada anterior
	for (int num = 1; num <= BOARD_SIZE; ++num) {
		if (esValido(sudoku, x, y, num)) {
			sudoku[x][y] = num;
			resolverSudoku(sudoku);
			if (!quedanVacias(sudoku))//Si todos los demás son válidos 'backtrack'.
				return;
		}

	}
	//Si no se ha encontrado ningún número válido, volver al valor por defecto
	//para que la llamada anterior vea que no se ha completado el tablero
	sudoku[x][y] = -1;
}


bool quedanVacias(int sudoku[BOARD_SIZE][BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; ++i)
		for (int j = 0; j < BOARD_SIZE; ++j)
			if (sudoku[i][j] == START_VALUE)
				return true;

	return false;
}

void mostrarSudoku(int sudoku[BOARD_SIZE][BOARD_SIZE])
{
	std::cout << "-------------------------------------------------------" << std::endl;
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			if (j == 0)
				std::cout << "|  ";
			std::cout << sudoku[i][j];
			if ((j + 1) % 3 == 0)
				std::cout << "  |  ";
			else
				std::cout << "     ";
		}
		std::cout << std::endl;
		if ((i + 1) % 3 == 0)
			std::cout << "-------------------------------------------------------" << std::endl;
	}
	std::cout << std::endl;
}


bool esValido(int sudoku[BOARD_SIZE][BOARD_SIZE], int fila, int columna, int valor) {

	for (int i = 0; i < BOARD_SIZE; ++i) {
		if (sudoku[fila][i] == valor) return false;
		if (sudoku[i][columna] == valor) return false;
	}
	
	int despFila = (fila / 3) * 3;
	int despColumna = (columna / 3) * 3;
	
	for (int i = despFila; i < despFila + 3; ++i)
		for (int j = despColumna; j < despColumna + 3; ++j)
			if (sudoku[i][j] == valor) return false;

	return true;
}
