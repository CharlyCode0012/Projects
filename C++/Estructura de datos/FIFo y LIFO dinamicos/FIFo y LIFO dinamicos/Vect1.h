#pragma once
#ifndef VECT1_H
#define VECT1_H

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Vect1
{
private:
	struct Nodo
	{
		int data;
		Nodo* next;
	};
	Nodo* inicio=nullptr, * cursor=nullptr, * temp=nullptr;
public:
	int size();
	int size(Nodo*);
	void append(int);
	void erase(int);
	void clean();
	void show();
	~Vect1() {};
};

#endif
