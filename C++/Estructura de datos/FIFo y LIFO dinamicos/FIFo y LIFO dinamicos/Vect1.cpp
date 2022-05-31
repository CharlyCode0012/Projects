#include "Vect1.h"

int Vect1::size()
{
	return size(inicio);
}

int Vect1::size(Nodo* head)
{
	if (head == nullptr)
		return 0;
	else
		return 1 + size(head->next);//secuencia a la cual se le aumenta 1 en cada vez que se llame al programa
}

void Vect1::append(int data)
{
	temp = new Nodo;//asignación de un nuevo espacio de memoria;
	cursor = inicio;
	temp->data = data;
	temp->next = nullptr;

	if (inicio == nullptr)//lista vacía
	{
		inicio = temp;
		return;
	}

	while (cursor->next != nullptr)//cuando se cumple estamos en la ultima lista
		cursor = cursor->next;

	cursor->next = temp;
	return;
}

void Vect1::erase(int posicion)
{
	int cont = 0;
	if (inicio == nullptr)//analiza si la lista esta vacía
	{
		cout << "\n\aLista vacia" << endl;
		system("pause");
		system("cls");
		return;
	}
	cursor = inicio;//se inicializa el cursor
	if (posicion == 0)//por si la posicion es la inicial
	{
		inicio = cursor->next;
		delete cursor;//en tal caso cursor es la primera posición y se elimina
		return;
	}

	for (int i = 0; cursor != nullptr && i < posicion - 1; i++)//se encuentra el nodo previo a borrar
	{
		cursor = cursor->next;
		cont++;
	}

	if (cursor == nullptr || cursor->next == nullptr)//se analiza si el indice ingresado es mayor a la cantidad de elementos que hay.
	{
		cout << "\n\n Wrong size...\n\n";
		system("pause");
		system("cls");
		return;
	}
	
	temp = cursor -> next -> next;//Se apunta al nodo (puntero) siguiente del que se va a borrar.
	delete cursor->next;//se borra el nodo siguiente (cursor es previo al nodo a borrar)
	cursor->next = temp;//se hace un enlace con el nodo que previamente se apunto.
}

void Vect1::clean()
{
	cursor = inicio;
	if (cursor == nullptr)
	{
		return;
	}
	else
	{
		while (cursor != nullptr)
		{
			temp = cursor;
			cursor = cursor->next;
			delete temp;
		}
	}
	inicio = nullptr;
	delete cursor;
}

void Vect1::show()
{
	cursor = inicio;
	int len = size(inicio);
	if (size(inicio) - 1 >= 0)//se analiza por si se usa este metodo después de borrar el arreglo o antes de crearlo.
	{
		cout << "\n\n\t\t { ";
		for (int j = 0; j <= size(inicio) - 1 && cursor != nullptr; j++)
		{
			cout << "[" << cursor->data << "] ";
			cursor = cursor->next;
		}
		cout << "}" << endl;
	}
	else
		cout << "\n\n Wrong size";
}