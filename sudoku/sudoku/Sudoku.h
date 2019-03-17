#pragma once
#include "Casilla.h"

class Sudoku
{
public:
	void inicializarSudoku() ;
	void introduirNum();
	void treureNum();
	void mostrarSudoku()const;
	bool comprobarCasilla(int& const num, int& const fila, int& const columna) const;
	bool comprobarSudoku() const;
	bool comprobarCuadro(int& const num, int& const fila, int& const colum) const;

private:
	Casilla sudoku[9][9];
};