#include "Vect1.h"

int menu2();

int main()
{
    int num = 0, opc_m1 = 0, opc_m2 = 0, value = 0;
    Vect1 obj;
    while (true)
    {
        while (true)
        {
            cout << "\n\n\t\t\t ~~Menu~~\n\n\t 1 \t First in, First out\n\t 2 \t First in, Last out\n\t 3 \t Salir\n\n Opcion: ";
            try
            {
                cin >> opc_m1;
                cin.ignore();
                if (opc_m1 != 1 && opc_m1 != 2 && opc_m1 != 3)
                    throw;
                break;
            }
            catch (...)
            {
                cout << "\n\n wrong data";
            }

        }
        cout << endl;
        if (opc_m1 == 3)
            break;
        system("pause");
        system("cls");
        if (opc_m1 == 1)
        {
            while (true)//FIFO
            {
                opc_m2 = menu2();
                switch (opc_m2)
                {
                case 1:
                    cout << "\n Ingrese un valor numerico entero\n\n Numero: ";
                    cin >> value;
                    obj.append(value);
                    break;
                case 2:
                    obj.erase(0);
                    break;
                case 3:
                    obj.show();
                    break;
                case 4:
                    obj.clean();
                    break;
                }
                if (opc_m2 == 4)
                    break;
            }
        }
        else
        {
            while (true)
            {
                opc_m2 = menu2();//FILO
                switch (opc_m2)
                {
                case 1:
                    cout << "\n Ingrese un valor numerico entero\n\n Numero: ";
                    cin >> value;
                    obj.append(value);
                    break;
                case 2:
                    obj.erase(obj.size() - 1);
                    break;
                case 3:
                    obj.show();
                    break;
                case 4:
                    obj.clean();
                    break;
                }
                if (opc_m2 == 4)
                    break;
            }
        }
    }
}

int menu2()
{
    int opcion = 0;
    cout << "\n\n\t\t\t ~~Menu2~~\n\n\t 1 \t Insertar\n\t 2 \t Eliminar\n\t 3 \t Mostrar\n\t 4 \t Salir\n\n Opcion: ";
    try
    {
        cin >> opcion;
        cin.ignore();
        if (to_string(opcion).size() == 0 || to_string(opcion).size() > 1)//solo se requiere de 1 carcater
            throw "Wrong size";
        if (!isdigit(to_string(opcion)[0]))//numeros-->isdigit
            throw "wrong type of data";
        if (opcion < 1 && opcion>4)
            throw 12;
        system("cls");
    }
    catch (...)
    {
        cout << "\n\n\a Wrong data**\n\n";
        system("pause");
        system("cls");
        menu2();
    }
    return opcion;
}