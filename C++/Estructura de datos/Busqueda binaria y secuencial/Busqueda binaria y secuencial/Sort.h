#ifndef Sort_H
#define Sort_H
#include <iostream>
#include <stdlib.h>
#include <string>
 /* aqui se agregaron la mayoria de librerias que son requeridas por ende no hay necesidad de volveras a poner al usar esta cabezera
    en esta parte solamente se inicializa los metodos y atributos de la clase*/
using namespace std;

class Sort
{
	unsigned int tamaño = 0;
	int* p = new int[tamaño];
	string cadena="";
public:
	Sort(int x) : tamaño(x) {};//se iniciliza el atributo "tamaño" por el metodo de lista
	void InP();
	bool ValidarNum(string, bool);
	void Permutar(int*, int*);
	void Selection();
	int Binary(int);
	int Secuencial(int, bool);
	void ShowArr(unsigned int);
	void ClearArr();
	~Sort();
};
#endif
