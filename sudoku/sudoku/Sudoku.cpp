#include "Sudoku.h"
using namespace std;

void Sudoku::inicializarSudoku()   // inicializa el sudoku con archivo txt
{
	ifstream miArchivo;
	int output;
	//bool ok = true;

	miArchivo.open("sudoku1.txt"); //abre txt

	if (miArchivo.is_open())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{//for para inicializar el sudoku
				miArchivo >> output;
				if (output >= 0 && output <= 9)
				{
					sudoku[i][j].setCasilla(output);
					if (sudoku[i][j].getCasilla() != 0) //settea la casilla como Origen
					{
						sudoku[i][j].setOrigen(true);
						sudoku[i][j].setLibre(false);
					}
				}
			}
		}
	}
}

void Sudoku::introduirNum() 
{
	int num, fila, columna;
	cout << "Numero a introducir: ";
	cin >> num;
	cout << "Casilla del numero (fila y columna): ";
	cin >> fila >> columna;
	columna--;
	fila--;
	if (comprobarCasilla(num, fila, columna) && comprobarCuadro(num, fila, columna)) // comprueba que no esta la columna y fila libres
	{
		if (sudoku[fila][columna].getLibre() == true) //si es libre es modificable
		{
			sudoku[fila][columna].setCasilla(num); //mete el numero
			sudoku[fila][columna].setLibre(false); //no puedes tocar sin quitar el numero
		}
		else
			cout << "ERROR: Casilla ocupada." << endl;
	}
	else
		cout << "ERROR: Valor repetido." << endl;
}

void Sudoku::treureNum()  //quita un numero Libre
{
	int fila, columna;
	cout << "Casilla a eliminar (fila y columna): ";
	cin >> fila >> columna;

	if (sudoku[fila-1][columna-1].getOrigen() == true) //no puedes tocar las Original
		cout << "ERROR: No se puede eliminar una casilla original." << endl;
	else
	{
		sudoku[fila-1][columna-1].setCasilla(0);
		sudoku[fila-1][columna-1].setLibre(true); //se vuelve libre
	}
}

void Sudoku::mostrarSudoku() const //enseña sudoku
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << sudoku[i][j].getCasilla() << " ";
		}
		cout << endl;
	}
}

bool Sudoku::comprobarCasilla(int& const num, int& const fila, int& const columna) const //busca el numero en la fila y columna
{
	bool valid = true;

	for (int i = 0; i < 9; i++)
	{
		if (sudoku[i][columna].getCasilla() == num)
		{
			valid = false;							//si el numero esta repetido, no te lo deja poner
		}
	}

	for (int j = 0; j < 9; j++)
	{
		if (sudoku[fila][j].getCasilla() == num)
		{
			valid = false;							//^same
		}
	}

	return valid;
}

bool Sudoku::comprobarSudoku() const//comprueba si sudoku ha terminado
{
	bool acabat = true;
	int i = 0;
	int j = 0;

	while (i < 9 && acabat == true)
	{
		while (j < 9 && acabat == true)
		{
			if (sudoku[i][j].getCasilla() == 0) //si la casilla es 0 no esta terminado
				acabat = false;					
			j++;
		}
		i++;
	}
	return acabat; //si las casillas son != a 0 todas, termina el sudoku
}

bool Sudoku::comprobarCuadro(int& const num, int& const fila, int& const colum) const//busca el numero en el cuadro
{
	bool valid = true;
	int filaInt = fila / 3, columInt = colum / 3, i = 0, j = 0;
	filaInt *= 3;
	columInt *= 3;

	while (i < (filaInt + 3) && valid)
	{
		while (j < (columInt + 3) && valid)
		{
			if (sudoku[filaInt][columInt].getCasilla() == num)
				valid = false;
			else
				j++;
		}
		i++;
	}
	
	
	return valid;
}