#ifndef vect1_H
#define vect1_H

#include <iostream>
#include <stdlib.h>
using namespace std;


class vect1
{
private:
	unsigned int tamanio = 0;
	int* ve_ = new int[20];
public:
	vect1() {};
	unsigned int begin();
	unsigned int end();
	int size();
	void erase(int);
	void reacomodo();
	void show();
	void ingresar();
	void FILO(int);
	void FIFO(int);
	~vect1() { delete[] ve_; tamanio = 0; };
};

#endif