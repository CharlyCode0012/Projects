#include "vect1.h"
#include <string>

int menu();

int main()
{
    int num = 0, opc_m1 = 0, opc_m2 = 0;
    vect1 obj;
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
                opc_m2 = menu();
                if (opc_m2 != 4)
                    obj.FIFO(opc_m2);
                else
                    break;
            }
        }
        else
        {
            while (true)
            {
                opc_m2 = menu();//FILO
                if (opc_m2 != 4)
                    obj.FILO(opc_m2);
                else
                    break;
            } 
        }
    }
}

int menu()
{
    int opcion=0;
        cout << "\n\n\t\t\t ~~Menu2~~\n\n\t 1 \t Insertar\n\t 2 \t Eliminar\n\t 3 \t Mostrar\n\t 4 \t Salir\n\n Opcion: ";
        try
        {
            cin >> opcion;
            cin.ignore();
            if (to_string(opcion).size() == 0||to_string(opcion).size()>1)//solo se requiere de 1 carcater
                throw "Wrong size";
            if (!isdigit(to_string(opcion)[0]))//numeros
                throw "wrong type of data";
            if (opcion <1 && opcion>4)
                throw 12;
            system("cls");
        }
        catch (...)
        {
            cout << "\n\n\a Wrong data**\n\n";
            system("pause");
            system("cls");
            menu();
        }
    return opcion;
}
