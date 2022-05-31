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
	Nodo* inicio = nullptr, * cursor = nullptr, * temp = nullptr, *aux=nullptr;
	int indice = 0;
public:
	int size();
	int size(Nodo*);
	void append(int);
	void erase(int);
	void pop(int);
	void modificar(int);
	void buscar(int);

	struct Nodo* buscar(Nodo* ref, int value)
	{
		aux = ref;
		if (aux == nullptr)
			return aux;
		if (aux->data == value)//primer elemento i=0
		{
			indice = 0;
			return aux;//mismo elemento
		}
		if (aux->next!=nullptr&&aux->next->data == value)//elemento 2, si es que solo hay 2 elementos
		{
			indice = 1;
			return aux;//nodo anterior
		}
		while (aux->next != nullptr && aux->next->data != value)//caso en que haya más de 2 elementos
		{
			indice++;
			aux = aux->next;
		} 
		if (aux->next== nullptr)//No se encontro el elemento
		{
			indice = -1;
			aux = nullptr;
		}
		return aux;//regresa el nodo anterior en caso de encontrar el elemento
	}
	void show();
	~Vect1();
};
#endif