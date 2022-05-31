#include "Sort.h"

void Sort::InP()//metodo en el cual el objeto guarda su arreglo
{
	bool flag = false;
	for (unsigned int i = 0; i < tamaño; i++)
	{
		while (true)
		{
			cout << "\nIngrese el numero " << i + 1 << ": ";
			cin >> cadena;
			flag = ValidarNum(cadena,false);
			if ((i + 1) % 5 == 0)//limpiar pantalla cada 5 valores ingresados
				system("cls");
			if (flag == false)
			{
				system("cls");
				cadena.erase(cadena.begin(), cadena.end());
			}
			else
				break;
		}
		p[i] = stoi(cadena, nullptr, 10);
		cadena.erase(cadena.begin(), cadena.end());
	}
 }

bool Sort::ValidarNum(string array1, bool flag)/*la funcion de la bander es saber si se habla del tamaño del arreglo o no.
											      false ---> tamaño       true ---> no es el tamaño     */
{
	bool value= false;
	int j = 0;
	while (array1.size() > 1 && array1[j] == ' ')//se borran los espacios
	{
		array1.erase(array1[j]);
		j++;
	}
	int inicio = array1[0] == '-';//se almacena el menos

	for (unsigned int i = inicio; i < array1.size(); i++)
	{
		if (array1[i] >= '0' && array1[i] <= '9')
			value = true;
		else
		{
			value = false;
			break;
		}
	}	
	if (value == true && flag == true)//asigna el tamaño al arreglo
		tamaño = stoi(array1);
	return value;
}

void Sort::Permutar(int*num1, int*num2)//metodo swap/intercambio de posiciones, n1>n2
{
	int aux = *num1;
	*num1 = *num2;
	*num2 = aux;
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
			Permutar(&p[max], &p[i - 1]);
	}
}

int Sort::Binary(int elemento)
{
	int resultado = 0, ultimo = 0, medio = 0, primera=0;
	ultimo=tamaño-1;
	medio = ultimo / 2;
	while (primera<=ultimo)
	{
		if (p[medio] < elemento)
		{
			primera = medio + 1;//la primera posicion será la soguiente del punto medio actual
		}
		else
			if (p[medio] == elemento)
			{
				resultado = medio+1;
				break;
			}
			else
				ultimo = medio - 1; //la ultima posicion sera una antes del punto medio actual
		medio = (primera + ultimo) / 2;//formula de media.
	}
	return resultado;
}

int Sort::Secuencial(int elemento, bool flag_)
{
	int resultado = 0;
	for (unsigned int i = 0; i < tamaño; i++)
	{
		if (flag_ == true && p[i] > elemento)
			break;
		if (p[i] == elemento)
		{
			resultado = i + 1;
			break;
		}
	}
	return resultado;
}

void Sort::ShowArr(unsigned int Len)
{
	if (Len-1>=0)//se analiza por si se usa este metodo después de borrar el arreglo o antes de crearlo. es decir el array esta vacio 
	{
		cout << "\n\n\t\t { ";
		for (unsigned int j = 0; j <= Len-1; j++)
			cout << "[" << p[j] << "] ";
		cout << "}" << endl;
	}
	else
		cout << "\n\n Wrong size";
	
}

void Sort::ClearArr()//metodo para borrar el contenido del objeto.
{
	tamaño = 0;
	p = 0;
	delete[] p;
}

Sort::~Sort()//destructor
{ }