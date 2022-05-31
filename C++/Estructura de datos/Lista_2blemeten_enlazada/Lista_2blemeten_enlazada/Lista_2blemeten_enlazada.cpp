#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class _List2
{
private:
	struct Node {
		Node() : val(0), pos(0), siguiente(nullptr), prev(nullptr) {}
		Node* siguiente, * prev;
		int val, pos;
	};

	Node almacen;
public:
	enum click { izquierda = 75, derecha = 77 };
	_List2() {}
	void push(const int _val);
	const int find(const int _which);
	void remover(const int _which);
	void remplazar(const int _which, const int _val);
	void show(const int _key, Node* _where = nullptr);
	void clear();
};

void _List2::push(const int _val)
{
	Node* iterador = &this->almacen;

	while (iterador->siguiente) iterador = iterador->siguiente;

	iterador->val = _val;
	iterador->siguiente = new Node;
	iterador->siguiente->prev = iterador;
	iterador->siguiente->pos = iterador->pos + 1;
}

const int _List2::find(const int _which)
{
	for (Node* iterador = &this->almacen; iterador->siguiente; iterador = iterador->siguiente)
		if (iterador->val == _which) return iterador->pos;

	return -1;
}

void _List2::remover(const int _which)
{
	Node* iterador = &this->almacen;

	while ((iterador->siguiente && iterador->val != _which)) iterador = iterador->siguiente;

	while (true)
	{
		if (!iterador->siguiente->siguiente)
		{
			delete iterador->siguiente;
			iterador->val = 0;
			iterador->siguiente = nullptr;
			return;
		}

		iterador->val = iterador->siguiente->val;
		iterador = iterador->siguiente;
	}
}

void _List2::remplazar(const int _which, const int _val)
{
	Node* iterador = &this->almacen;

	while ((iterador->siguiente && iterador->val != _which)) iterador = iterador->siguiente;

	iterador->val = _val;
}

void _List2::show(const int _key, Node* _where)
{
	if (!this->almacen.siguiente)
	{
		cout << "\n[ ]\n";
		return;
	}

	cout << "\n ";
	Node* iterador = _where ? _where : &this->almacen;

	if (_key == this->izquierda && !_where)
		while ((iterador->siguiente && iterador->siguiente->siguiente)) iterador = iterador->siguiente;

	for (int i = 0; i < 3; i++)
	{
		cout << iterador->val;

		if (_key == this->derecha)
		{
			cout << ((iterador->siguiente && iterador->siguiente->siguiente && i != 2) ? ", " : " \n");

			if (!iterador->siguiente) return;

			iterador = iterador->siguiente;
		}
		else
		{
			cout << ((iterador->prev && i != 2) ? ", " : " \n");

			if (!iterador->prev) return;

			iterador = iterador->prev;
		}
	}

	char click = NULL;

	while ((click != this->izquierda && click != this->derecha)) click = _getch();

	if (click == this->izquierda) cout << "<-\n";
	if (click == this->derecha) cout << "->\n";

	return show(click, iterador);
}

void _List2::clear()
{
	Node* iterador = &this->almacen;

	while ((iterador->siguiente && iterador->siguiente->siguiente)) iterador = iterador->siguiente;

	while (iterador->prev)
	{
		delete iterador->siguiente;
		iterador = iterador->prev;
	}
}



int main()
{
	system("color 80");
	_List2 lista;
	char click = NULL;
	int val = 0, opcion = 0;

	while (opcion != 6)
	{
		system("cls");
		cout << "\t\t\t LISTAS DOBLEMENTE ENLAZADAS" << endl << endl;
		cout << "\t\t ~Menu~" << endl;
		cout << "\t 1.- Insertar elemento" << endl;
		cout << "\t 2.- Eliminar elemento" << endl;
		cout << "\t 3.- Modificar elemento" << endl;
		cout << "\t 4.- Buscar elemento" << endl;
		cout << "\t 5.- Mostrar lista" << endl;
		cout << "\t 6.- salir\n\n";
		cout << " Opcion: ";
		cin >> opcion;
		while (opcion > 6 || opcion < 1) {
			cout << "ingresa un dato correcto del menu";
			cin >> opcion;
		}
		switch (opcion)
		{
		case 1:
			cout << endl << "Ingresa el numero: ";
			cin >> val;
			lista.push(val); // Añade un elemento a la lista
			cout << endl << "fue ingresado a la lista el numero: " << val << "\n\n";
			system("pause");
			break;
		case 2:
			cout << endl << "Ingrese el numero que desea eliminar: ";
			cin >> val;
			// Verifica si el numero esta en la lista
			if (lista.find(val) == -1)
			{
				cout << endl << "No esta en la lista el elemento: " << val << "\n\n";
				system("pause");
				break;
			}

			lista.remover(val); // Elimina tal elemento de la lista
			cout << endl << "El numero eliminado fue: " << val << "\n\n";
			system("pause");
			break;
		case 3:
		{
			int remplazar = 0; // Variable para almacenar el elemento que se quiere modificar

			cout << endl << "Ingresa el numero a eliminar: ";
			cin >> val;
			// Verificar si el numero esta en la lista
			if (lista.find(remplazar) == -1)
			{
				cout << endl << "No esta en la lista el elemento: " << val << "\n\n";
				system("pause");
				break;
			}

			cout << endl << "Ingrese el nuevo valor para el elemento: ";
			cin >> remplazar;
			lista.remplazar(remplazar, val); // Reemplazar tal numero por uno nuevo
			cout << endl << "\n\n El elemento: " << remplazar << " fue modificado" << endl;
			cout << "el nuevo valor es: " << val << "\n\n";
			system("pause");
			break;
		}
		case 4:
			cout << endl << "Ingrese el valor del elemento que desea encontrar: ";
			cin >> val; 

			if (lista.find(val) == -1)
				cout << endl << "No esta en la lista el elemento: " << val << "\n\n";
			else
				cout << "\n\n" << "El elemento: " << val << " se encuentra en la posicion:" << lista.find(val) + 1 << endl;

			cout << "\n\n";
			system("pause");
			break;
		case 5:
			while ((click != lista.izquierda && click != lista.derecha))
			{
				system("cls");
				cout << " De que manera la quieres ver: " << endl;
				cout << "hacia la derecha * -> * secuencial " << endl;
				cout << "hacia la izquierda * <- * reverso " << endl;
				click = _getch();

				if (click != -32) continue;

				click = _getch();
			}
			
			if (click == lista.izquierda) cout << "flecha hacia la izquierda <-" << endl;
			if (click == lista.derecha) cout << "flecha hacia la derecha ->" << endl;

			lista.show(click);
			click = NULL;
			system("pause");
			break;
		default:
			if (opcion != 6)
				cout << "\n\n Ingrese datos validos \n\n";
			else
				cout << "\n\n\t\t\t Saliendo...\n\n";
			break;
		}
		
	}
	lista.clear();
	return 0;
}