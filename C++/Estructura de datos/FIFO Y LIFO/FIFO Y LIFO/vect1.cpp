#include "vect1.h"


unsigned int vect1::begin()
{
	unsigned int ini = 0;
	return ini;
}


unsigned int vect1::end()
{
	unsigned int fin = tamanio - 1;
	return fin;
}


 int vect1::size()
{
	int count = tamanio;
	return count;
}


void vect1::erase(int iterator)
{
	unsigned int i = iterator;
	

	if (tamanio > 0)
	{
		ve_[iterator] = NULL;
		tamanio -= 1;
	}
		
}

void vect1::reacomodo()
{
	if (size() > 0)
	{
		for ( int i = 0; i < size(); i++)
		{
			ve_[i] = ve_[i + 1];
		}
		ve_[size() + 1] = NULL;
	}
	else
		ve_[0] = NULL;
}

void vect1::show()
{
	if (size() - 1 >= 0)//se analiza por si se usa este metodo después de borrar el arreglo o antes de crearlo.
	{
		cout << "\n\n\t\t { ";
		for ( int j = 0; j <= size() - 1; j++)
			cout << "[" << ve_[j] << "] ";
		cout << "}" << endl;
	}
	else
		cout << "\n\n Wrong size";
}

void vect1::ingresar()
{
	int num = 0, r = 0, i=0;
	while (true)
	{
		if (tamanio <= 18)
		{
			tamanio += 1;
			if (i > 0)
				for (int j = 0; j < i; j++)
					cout << "\n Ingrese el numero " << j + 1 << ": " << ve_[j];

			cout << "\n Ingrese el numero " << i + 1 << ": ";
			cin >> num;
			ve_[i] = num;
			i++;
			cout << "\n\n Ingrese 1 si quiere dejar de ingresar\n Respuesta: ";
			cin >> r;
			system("cls");
			if (r == 1 || i >= 19) { break; }
		}
		else
		{
			cout << "\n\n El arreglo esta lleno**" << endl;
			system("pause");
		}
	}
}
auto vect1::FILO(int sw)->void //1--> insertar, 2--> eliminar, 3--> mostrar.
{
	switch (sw)
	{
	case 1:
		ingresar();
		break;
	case 2:
		if (size() > 0)
			erase(end());
		else
		{
			cout << "\n\n Arreglo vacio\n";
			system("pause");
			system("cls");
		}
		break;
	case 3:
		show();
		break;
	default:
		break;
	}	
}

auto vect1::FIFO(int sw)->void //1--> insertar, 2--> eliminar, 3--> mostrar.
{
	switch (sw)
	{
	case 1:
		ingresar();
		break;
	case 2:
		if (size() > 0)
		{
			erase(begin());
			reacomodo();
		}
		else
		{
			cout << "\n\n Arreglo vacio\n";
			system("pause");
			system("cls");
		}
		break;
	case 3:
		show();
		break;
	default:
		break;
	}
}