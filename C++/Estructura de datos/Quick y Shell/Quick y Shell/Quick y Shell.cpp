#include "Sort.h"

 int Parametro();

int main()
{
    system("cls");
    int size1 = 0;
    char Option;
    system("color 80");//cambia el color a fondo gris y fuente negra
    size1 = Parametro();
    Sort arreglo(size1);
    arreglo.Ingresar();
    system("pause");//detiene la ejecución hasta que se presione 1 tecla
    if (size1 % 5 != 0)
        system("cls");//se limpia el cmd
    cout << "seleccione un meotodo para ordenar el arreglo:\n\n\n A) Quick Sort\n B) Shell Sort\n\n\t\t Opcion: ";
    cin >> Option;
    Option = toupper(Option);
    switch (Option)
    {
    case 'A':
        arreglo.Mostrar();//muestra el arreglo
        arreglo.Quick();//ordena el arreglo del menor al mayor
        cout << "arreglo cambiado: "; arreglo.Mostrar();
        cout << "\n\n";
        //arreglo.clear_arr();//borra el arreglo y su "tamaño" esto sería util en caso de que no se quiera borrar todo el objeto y solo se quiera liberar este espacio de memoria
        break;
    case 'B':
        arreglo.Mostrar();
        arreglo.Shell();
        cout << "arreglo cambiado: "; arreglo.Mostrar();
        cout << "\n\n";
        //arreglo.clear_arr();
        break;
    default:
        cout << "\n\n\a\t\t\tWrong data...\n\n\n";
        system("pause");
        break;
    }
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
            if (num <= 0 || num >= 21)//Si la condición es cierta se manda una excepcion y repitiendo el bucle hasta que no haya alguna excepcion
                throw "Wrong size value";
            break;//rompe el ciclo si el rango es adecuado
        }
        catch (const char x[])//se le pasa el valor de throw
        {
            system("color 84");//fondo gris fuente roja
            cout << "\a\n\n " << x << endl;
            system("pause");
            system("color 80");
            system("cls");
        }

    }
    return num;
}