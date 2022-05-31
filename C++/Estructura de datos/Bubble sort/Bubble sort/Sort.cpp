#include "Sort.h"

void Sort::InP()//metodo en el cual el objeto guarda su arreglo
{
	for (unsigned int i = 0; i < tamaño; i++)
	{
		cout << "\nIngrese el numero " << i + 1 << ": ";
		cin >> p[i];
		if ((i+1) % 5 == 0)//limpiar pantalla cada 5 valores ingresados
			system("cls");
	}
}

void Sort::permutar(int*num1, int*num2)//metodo swap/intercambio de posiciones, n1>n2
{
	int aux = *num1;
	*num1 = *num2;
	*num2 = aux;
}

void Sort::Burbble()//metodo donde se encuentra el bubble sort para acomodar del menor a mayor
{
	bool flag_per; //bandera 
	for (unsigned int i = 0; i < tamaño; i++)
	{
		flag_per = false;
		for (unsigned int j = 0; j < tamaño-i-1; j++)
		{
			if (p[j] > p[j + 1])// al cambiar de posicion ahora el valor de j pasa a ser j+1, por lo que en la siguiente iteración ese valor se vuelve a evaluar            
			{                   //al no ser mayor el contenido de j, ahora se va a evaluar la expreion que en esa iteracion era j+1 (cuando se evalua pasa a ser j)

				permutar(&p[j], &p[j + 1]);
				flag_per = true; //se confirma que hubo por lo menos 1 cambio en esta iteracion de i
			}	
		}
		if (flag_per == false)
			break;
		else// se impre el arreglo con el nuevo orden que tiene
			Mostrar(tamaño);
	}
}

void Sort::Selection()
{
	unsigned int max=0;
	for ( unsigned int i = tamaño; i >0; i--)
	{
		max = 0;//en cada iteración se asume que el mayor es el primer valor
		for (unsigned int j = 1; j <= i-1; j++)
			if (p[j]>p[max])//se encuentra el indice con el contenido más grande
				max = j;

		if (i - 1 != max && p[i - 1] != p[max])//se analiza si los contenidos a permutar son diferentes o si no son el mismo indice
		{
			permutar(&p[max], &p[i - 1]);
			Mostrar(tamaño);
		}
	}
}

void Sort::Insertion()
{
	bool flag = false;
	int j = 0, temp;
	Mostrar(1);
	for (unsigned int i = 1; i < tamaño; i++)//comienza desde el 2do termino
	{
		temp = p[i];
		j = i - 1;//un valor antes de i
		while (p[j] > temp && j >= 0)//se analiza ciertas condiciones
		{
			p[j + 1] = p[j];//Los valores más grandes se recorren un lugar
			j--;
		}
		p[j + 1] = temp;//dependiendo si entro a ciclo o no es como actuara, sino entro retomara el valor de i, y si entro tomara la casilla que dejo disponible
		Mostrar(i + 1);//el mas uno para que tome en cuenta de 2 a mas datos
	}
}

void Sort::Merge(int final1)
{ Merge_(p, final1); }

void Sort::Merge_(int array1[], int final1)
{
	unsigned int mitad = final1 / 2;
	int* izq = new int[mitad];
	int* der = new int[final1 - mitad];
	if (final1 == 1) 
	{ 
		delete[] izq;
		delete[] der;
		return; 
	}
	else
	{
		for (int i = 0; i < mitad; i++)
			izq[i] = array1[i];
		for (int i = mitad; i < final1; i++)
			der[i - mitad] = array1[i];
		Merge_(izq, mitad);
		Merge_(der, final1 - mitad);
		Mezclar1(izq, mitad, der, final1 - mitad, array1);
	}
}



void Sort::Mezclar1(int* izq, int n_izq, int*der, int n_der, int*array1)
{
	int low_izq = 0, low_der = 0, it_array = 0;
	while ((low_izq < n_izq) && (low_der < n_der))
	{
		if (izq[low_izq] <= der[low_der])
		{
			array1[it_array] = izq[low_izq++];
		}
		else
		{
			array1[it_array] = der[low_der++];
		}
		it_array++;
	}
	while (low_izq < n_izq)
	{
		array1[it_array++] = izq[low_izq++];
	}
	while (low_der < n_der)
	{
		array1[it_array++] = der[low_der++];
	}
}

void Sort::Mostrar(unsigned int Len)
{
	if (Len-1>=0)//se analiza por si se usa este metodo después de borrar el arreglo o antes de crearlo.
	{
		cout << "\nArreglo: \n\n\t\t{ ";
		for (unsigned int j = 0; j <= Len-1; j++)
			cout << "[" << p[j] << "] ";
		cout << "}" << endl;
	}
	else
		cout << "\n\n Wrong size";
	
}

void Sort::clear_arr()//metodo para borrar el contenido del objeto.
{
	tamaño = 0;
	delete[] p;
}

Sort::~Sort()//destructor
{

}