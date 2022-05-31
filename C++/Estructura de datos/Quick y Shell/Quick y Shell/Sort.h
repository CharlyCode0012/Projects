
#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Sort
{
private:
	int tamanio = 0;
	int* p = new int[tamanio];
public:
	Sort(int x) : tamanio(x) {};
	void Ingresar();
	void Permutar(int*, int*);
	void Mostrar();
	void Quick();
	void Quick(int*, int, int);
	int Piv(int*, int, int);
	void Shell();
	void Shell(int*, int);
	void clear_arr();
	~Sort() {};
}; 


#endif

