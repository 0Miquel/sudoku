#pragma once //probando
#include <fstream>
#include <iostream>

class Casilla
{
public: 
	Casilla() { m_casilla = 0; m_libre = true; m_origen = false; } //constructor
	//getters y setters
	int getCasilla() const { return m_casilla; }
	bool getLibre() const { return m_libre; }
	bool getOrigen() const { return m_origen; }
	void setCasilla(int num) { m_casilla = num; }
	void setLibre(bool libre) { m_libre = libre; }
	void setOrigen(bool origen) { m_origen = origen; }

private:
	int m_casilla;
	bool m_libre;
	bool m_origen;

};

