#ifndef Sort_H
#define Sort_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stdio.h>
 /* aqui se agregaron la mayoria de librerias que son requeridas por ende no hay necesidad de volveras a poner al usar esta cabezera
    en esta parte solamente se inicializa los metodos y atributos de la clase*/
using namespace std;

class Sort
{
	unsigned int tama�o = 0;
	int* p = new int[tama�o];
public:
	Sort(int x) : tama�o(x) {};//se iniciliza el atributo "tama�o" por el metodo de lista
	void InP();
	void permutar(int*, int*);
	void Burbble();
	void Selection();
	void Insertion();
	void Merge(int);
	void Merge_(int*, int);
	void Mezclar1(int*, int, int*, int, int*);
	void Mostrar(unsigned int);
	void clear_arr();
	~Sort();
};
#endif
