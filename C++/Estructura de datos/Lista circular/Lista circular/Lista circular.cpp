#include "List_Ci.h"

int menu2();
int validar();

int main()
{
    int opc_m2 = 0, value = 0;
    List_Ci obj;
    system("color 80");

    while (true)//FIFO
    {
        system("cls");
        opc_m2 = menu2();
        switch (opc_m2)
        {
        case 1:
            cout << "\n Ingrese un valor numerico entero\n\n Numero: ";
            cin >> value;
            obj.append(value);
            break;
        case 2:
            system("cls");
            cout << "\n Que elemento quieres buscar? ";
            value = validar();
            obj.buscar(value);
            break;
        case 3:
            system("cls");
            cout << "\n Que elemento quieres borrar? ";
            value = validar();
            obj.pop(value);
            break;
        case 4:
            system("cls");
            cout << "\n Que elemento quieres editar? ";
            value = validar();
            obj.modificar(value);
            break;
        case 5:
            cout << "\n\n\t\t\t ~~Arreglo~~\n\n";
            obj.show();
            break;
        case 6:
            cout << "\n\n Saliendo...\n";
            break;
        }
        if (opc_m2 == 6)
            break;

        cout << "\n\n";
        system("pause");
    }
}


int menu2()
{
    int opcion = 0;
    while (true)
    {
        cout << "\n\n\t\t\t ~~Menu2~~\n\n\t 1 \t Insertar\n\t 2 \t Buscar\n\t 3 \t Eliminar\n\t 4 \t Editar\n\t 5 \t Mostrar\n\t 6 \t Salir\n\n Opcion: ";
        opcion = validar();
        if (opcion < 1 || opcion > 6)//rango
        {
            cout << "\n\n\a Wrong data**\n\n";
            system("pause");
            system("cls");
        }
        else
            break;
    }
    return opcion;
}

int validar()
{
    int value = 0;
    try
    {
        cin >> value;
        if (to_string(value).size() == 0)
            throw "Wrong size";
        for (int i = 0; i < to_string(value).size(); i++)
        {
            if (!isdigit(to_string(value)[i]))//numeros-->isdigit
                throw "wrong type of data";
        }
        system("cls");
        return value;
    }
    catch (...)
    {
        cout << "\n\n\a Wrong data**\n\n";
        system("pause");
        system("cls");
        validar();
    }
}