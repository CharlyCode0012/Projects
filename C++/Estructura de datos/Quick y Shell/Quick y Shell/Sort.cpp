#include "Sort.h"

void Sort::Ingresar()
{
	for (unsigned int i = 0; i < tamanio; i++)
	{
		cout << "\nIngrese el numero " << i + 1 << ": ";
		cin >> p[i];
		if ((i + 1) % 5 == 0)//limpiar pantalla cada 5 valores ingresados
			system("cls");
	}
}

void Sort::Permutar(int* num1, int* num2)//metodo swap/intercambio de posiciones, n1>n2
{
	int aux = *num1;
	*num1 = *num2;
	*num2 = aux;
}

void Sort::Mostrar()
{
	if (tamanio - 1 >= 0)//se analiza por si se usa este metodo después de borrar el arreglo o antes de crearlo.
	{
		cout << "\n\n\t\t{ ";
		for (unsigned int j = 0; j <= tamanio - 1; j++)
			cout << "[" << p[j] << "] ";
		cout << "}" << endl;
	}
	else
		cout << "\n\n Wrong size";

}

void Sort::Quick()
{
	Quick(p, 0, tamanio-1);
}
void Sort::Quick(int* Arg, int inicio, int fin)
{
	int pivote;
	if (inicio < fin)
	{
		pivote = Piv(Arg, inicio, fin);
		Quick(Arg, inicio, pivote);
		Quick(Arg, pivote+1 , fin);
	}
}

int Sort:: Piv(int* Arg, int inicio, int fin)
{
	int pivote = Arg[inicio], izq = inicio, der = fin;
	while (true) {

		while (Arg[izq] < pivote) 
		{
			izq++;
		}
		while (Arg[der] > pivote) 
		{
			der--;
		}
		/*
		Si la izquierda es mayor o igual que la derecha significa que no
		necesitamos hacer ningún intercambio
		de variables, pues los elementos ya están en orden (al menos en esta
		iteración)
		*/
		if (izq >= der)
		{
			// Indicar "en dónde nos quedamos"
			return der;
		}
		else 
		{
			Permutar(&Arg[izq], &Arg[der]);
			izq++;
			der--;
		}
		// El while se repite hasta que izquierda >= derecha
	}
}


void Sort::Shell()
{
	Shell(p, tamanio);
}

void Sort::Shell(int* Arg, int fin)
{
	int temp, medio=fin/2, p, j;
	do {
		for (p = medio + 1; p < fin; p++) {
			temp = Arg[p];
			j = p - medio;
			while ((j >= 0) && (temp < Arg[j])) {
				Arg[j + medio] = Arg[j];
				j -= medio;
			}
			Arg[j + medio] = temp;
		}
		medio /= 2;
	} while (medio > 0);
}

void Sort::clear_arr()//metodo para borrar el contenido del objeto.
{
	tamanio = 0;
	delete[] p;
}

