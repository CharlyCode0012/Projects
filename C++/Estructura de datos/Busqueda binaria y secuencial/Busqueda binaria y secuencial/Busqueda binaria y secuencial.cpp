#include "Sort.h"

int Parametro(Sort*);
bool ValidarArr(string*);
void Select(char, Sort*, int, bool);

int main()
{
	string answer="";
	do
	{
		system("color 80");
		unsigned int size1 = 0;
		bool flag = true, flag_2 = true, flag_sel=false;
		string option = "";
		Sort array1(0);
		size1=Parametro(&array1);//se valida el valor ingresado (debe ser numerico)
		array1.InP();
		while (true)
		{
			system("cls");
			cout << "\n\t\t\t ~~Menu~~\n\n\t A: \t Busqueda Binaria\n\n\t B: \t Busqueda secuencial\n Nota: en busqueda binaria el arreglo sera modificado de manera ascendente\n\n Opcion: ";
			cin >> option; 
			cout << "\n\n";
			flag = ValidarArr(&option);;//se pasa por referencia paa modificar de una vez la string, retorno false si son puras letras
			system("pause");
			system("cls");
			if (flag == false && option.size() == 1)
			{ 
				cout << " Arreglo incial: ";
				array1.ShowArr(size1);
				cout << "\n";
				switch (option[0])
				{
				case 'A':
					array1.Selection();//se ordena el arreglo
					cout << " El nuevo orden es: ";
					array1.ShowArr(size1);
					Select(option[0], &array1, size1, true);
					break;
				case 'B':
					cout << "Quiere la version mejorada de la busqueda?\n\n Nota: en la version mejorada el arreglo cambia de orden ya que se pone de manera ascendente";
					cout << "\n Respuesta: ";
					cin >> answer;
					if (ValidarArr(&answer) == false && answer == "SI")//se analiza si el usuario quiere el metodo mejorado o no
					{
						array1.Selection();
						system("cls");
						cout << "\n El nuevo orden es: ";
						array1.ShowArr(size1);
						flag_sel = true;
					}
					else
					{
						flag_sel = false;//condicion para saber cuando parar en las busquedda secuencial
					}	
					Select(option[0], &array1, size1, flag_sel);
					break;
				default:
					cout << "\a\n\n\n Opcion fuera de rango...";
					break;
				}
				if (option[0] == 'A' || option[0] == 'B')
					break;
			}
		}
		while (flag_2 == true)
		{
			answer = "";
			cout << "\n\n Quiere continuar en el programa?\n\n Respuesta: ";
			cin >> answer; 
			cout << "\n\n";
			flag_2 = ValidarArr(&answer);
			system("pause");
			system("cls");
		}
		if (answer == "SI")
			array1.ClearArr();
	} while (answer=="SI");
}

int Parametro(Sort *obj)
{
	string num;
	bool flag = true;

	while (true)
	{
		cout << " Ingrese la cantidad de numeros que quiera ingresar\n\n Nota: Solo puede ingresar un maximo de 20 numeros\n\n\t Cantidad: ";
		cin >> num;
		flag = obj->ValidarNum(num, true);//se accede al metodo desde un puntero
		try
		{
			if (flag == false)//excepciones que se presentan
				throw "Wrong type of data";
			if (stoi(num) < 1 || stoi(num) > 20)
				throw "Wrong size value";
			else
				break;
		}
		catch (const char x[])
		{
			cout << "\a\n\n " << x << endl;
			system("color 84");//fondo gris fuente roja
			system("pause");
			system("cls");
			system("color 80");
		}
	}
	return stoi(num);
}

bool ValidarArr(string *Answer)
{
	bool value=false;//el valor falso es el que quiero obtener
	for (unsigned int i = 0; i < Answer->size(); i++)
	{
		if (Answer[0][i] >= 92 && Answer[0][i] <= 122)
			Answer[0][i] = toupper(Answer[0][i]);
		if (Answer[0][i] >= 48 && Answer[0][i] <= 57)
		{
			value = true;//es numerico y el while seguira.
			break;
		}	
	}
	return value;
}

void Select(char option, Sort *array_, int size1, bool flag_)
{
	fflush(stdin);
	int posicion = 0, elemento=0;
	string num;
	cout << "\n\n Que numero quiere buscar en el arreglo?\n\n Numero a buscar: ";
	cin >> elemento;
	cout << "\n\n";
	system("pasue");
	system("cls");
	array_->ShowArr(size1);
	if (option == 'B')
		posicion = array_->Secuencial(elemento, flag_);
	else
		posicion = array_->Binary(elemento);

	if (posicion > 0)
		cout << "\n La posicion de la 1era aparcion del elemento " << elemento << " es: " << posicion << endl;
	else
		cout << "\a\n El elemento no existe" << endl;
	
}
