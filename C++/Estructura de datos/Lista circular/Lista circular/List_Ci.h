#ifndef LIST_C_H
#define LISTC_H

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class List_Ci
{
private:
	struct Nodo
	{
		int data;
		Nodo* next;
	};
	Nodo* inicio = nullptr, * cursor = nullptr, * temp = nullptr, * fin = nullptr;
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
		temp = ref;
		if (temp == nullptr)//lista vacia
			return temp;
		do
		{
			if (temp->next->data != value)
			{
				temp = temp->next;
			}
		} while (temp->next->data != value && temp != inicio);
		if (temp->next->data != value)//si es cierto no hay dato
		{
			temp = nullptr;
		}
		return temp;//regresa el nodo anterior en caso de encontrar el elemento
	}
	void show();
	~List_Ci();
};

#endif