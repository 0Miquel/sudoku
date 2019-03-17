#include "Sudoku.h"
#include <iostream>
using namespace std;

int main()
{
	//ifstream miArchivo;
	int opcio;
	Sudoku sudoku;

	sudoku.inicializarSudoku();
	sudoku.mostrarSudoku();

	do {
		cout << "1- INTRODUCIR NUMERO" << endl << "2- ELIMINAR NUMERO" << endl << "3- ABANDONAR PARTIDA" << endl;
		cin >> opcio;

		switch (opcio)
		{
		case 1: sudoku.introduirNum();
			break;
		case 2: sudoku.treureNum();
			break;
		case 3: cout << "Has abandonat la partida." << endl;
			break;
		default:
			break;
		}
		if (opcio == 1 || opcio == 2)
			sudoku.mostrarSudoku();
	} while (opcio != 3);

	system("PAUSE");
	return 0;
}