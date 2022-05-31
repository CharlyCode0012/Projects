#include "List_Ci.h"
int List_Ci::size()
{
	int x = size(inicio);
	return x<=1?x:x-1;
}

int List_Ci::size(Nodo* head)
{
	if (head == nullptr)
		return 0;
	else
	{
		if (head == fin)
			return 1;
		else
			return 1 + size(head->next);//secuencia a la cual se le aumenta 1 en cada vez que se llame al programa
	}	
}

void List_Ci::append(int data)
{
	temp = new Nodo;//asignación de un nuevo espacio de memoria;
	cursor = inicio;
	temp->data = data;
	temp->next = inicio;

	if (inicio == nullptr)//lista vacía
	{
		inicio = temp;
		inicio->next = inicio;
		fin = inicio;
		return;
	}

	while (cursor->next != inicio)//cuando se cumple estamos en la ultima lista
		cursor = cursor->next;

	cursor->next = temp;
	fin = temp;
	return;

}

void List_Ci::erase(int posicion)
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

	temp = cursor->next->next;//Se apunta al nodo (puntero) siguiente del que se va a borrar.
	delete cursor->next;//se borra el nodo siguiente (cursor es previo al nodo a borrar)
	cursor->next = temp;//se hace un enlace con el nodo que previamente se apunto.
}

void List_Ci::pop(int value)
{
	cursor = buscar(inicio, value);
	if (cursor != nullptr)
	{
		temp = inicio;//se inicializa el cursor
		if (cursor->next == inicio && size(inicio) == 1)
		{
			inicio = nullptr;
			fin = nullptr;
			delete cursor;
		}
		else
		{
			temp = cursor->next->next;
			if (temp == inicio)
				fin = cursor;
			if (cursor->next == inicio)
				inicio = temp;
			delete cursor->next;
			cursor->next = temp;
		}
	}
	else
	{
		cout << "\a\n\n Ese dato no existe\n\n";
	}
}

void List_Ci::modificar(int value)
{
	int new_value = 0;
	cursor = buscar(inicio, value);
	if (cursor != nullptr)
	{
		cout << "\n\n Ingresa el nuevo numero\n\n Numero: ";
		cin >> new_value;
		cursor->next->data = new_value;//cualquier posicion que no sea el primer nodo
	}
	else
		cout << "\a\n\n Ese dato no existe\n\n";
}

void List_Ci::buscar(int value)
{
	int cont = 1;
	if (inicio != nullptr)
	{
		cursor=buscar(inicio, value);
		temp = inicio;
		if (cursor!=nullptr)
		{
			for (cont; cont < size(inicio); cont++)
			{
				if (temp != cursor->next)
				{
					temp = temp->next;
				}
				else
					break;
			}
			cout << "\n\n El valor se encontro en la posicion: " << cont<< "\n\n";
			return;
		}
		cout << "\n\n No se encontro ese valor\n\n";
	}
	else
		cout << "\n\n Esta vacio\n\n";

	return;
}

void List_Ci::show()
{
	cursor = inicio;
	int len = size(inicio);
	len % 3 == 0 ? len : len += (3 - (len % 3));
	if (size(inicio) - 1 >= 0)//se analiza por si se usa este metodo después de borrar el arreglo o antes de crearlo.
	{
		for (int j = 0; j <= len - 1; j++)
		{
			if (j % 3 == 0)
				cout << "\n\n";
			cout << "[" << cursor->data << "] ";
			cursor = cursor->next;
		}
	}
	else
		cout << "\n\n Wrong size";
}

List_Ci::~List_Ci()
{
	cursor = inicio;
	if (cursor == nullptr)
	{
		return;
	}
	else
	{
		cursor = inicio->next;
		while (cursor != inicio)
		{
			temp = cursor;
			cursor = cursor->next;
			delete temp;
		}
	}
	inicio = nullptr;
	fin = nullptr;
	delete cursor; 
}