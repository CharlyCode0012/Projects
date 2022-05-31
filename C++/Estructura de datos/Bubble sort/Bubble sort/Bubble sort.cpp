#include "Sort.h"

int Parametro(); //protipo de funcion para obtener el taño del array
int main()
{
	string answer = "";
	do
	{
		system("cls");
		unsigned int size1 = 0;
		char Option;
		system("color 80");//cambia el color a fondo gris y fuente negra
		size1 = Parametro();
		Sort arreglo(size1);
		arreglo.InP();
		system("pause");//detiene la ejecución hasta que se presione 1 tecla
		if (size1 % 5 != 0)
			system("cls");//se limpia el cmd
		cout << "seleccione un meotodo para ordenar el arreglo:\n\n\n A)  Burbble Sort\n B) Selection Sort\n C) Insertion Sort\n D) Merge Sort\n\n\t\t Opcion: ";
		cin >> Option;
		Option = toupper(Option);
		switch (Option)
		{
		case 'A':
			arreglo.Mostrar(size1);//muestra el arreglo
			arreglo.Burbble();//ordena el arreglo del menor al mayor
			arreglo.clear_arr();//borra el arreglo y su "tamaño" esto sería util en caso de que no se quiera borrar todo el objeto y solo se quiera liberar este espacio de memoria
			break;
		case 'B':
			arreglo.Mostrar(size1);
			arreglo.Selection();
			arreglo.clear_arr();
			break;
		case 'C':
			arreglo.Insertion();
			arreglo.clear_arr();
			break;
		case 'D':
			arreglo.Merge(size1);
			arreglo.Mostrar(size1);
			arreglo.clear_arr();
			break;
		default:
			cout << "\n\n\a\t\t\tWrong data...\n\n\n";
			system("pause");
			continue;
		}
		cout << endl;
		cout << "\n\n Desea salir del programa?";
		cin >> answer;
		for (unsigned int i = 0; i < answer.size(); i++)
			answer[i] = toupper(answer[i]);
	} while (answer != "SI");

	cout << "\n\n\nSaliendo....\n\n";
	return 0;
}

int Parametro()
{
	int num = 0;
	while (true)
	{
		cout << " Ingrese la cantidad de numeros que quiera ingresas\n\n Nota: Solo puede ingresar un maximo de 20 numeros\n\n\t Cantidad: ";
		try
		{
			cin >> num;
			if (num <= 0 || num>=21)//Si la condición es cierta se manda una excepcion y repitiendo el bucle hasta que no haya alguna excepcion
				throw "Wrong size value";
			break;//rompe el ciclo si el rango es adecuado
		}
		catch (const char x[])//se le pasa el valor de throw
		{
			system("color 84");//fondo gris fuente roja
			cout << "\a\n\n " << x<<endl;
			system("pause");
			system("color 80");
			system("cls");
		}

	}
	return num;
}
