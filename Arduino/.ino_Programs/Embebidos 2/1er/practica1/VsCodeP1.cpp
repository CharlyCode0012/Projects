#include <iostream>
#include <windows.h>

using namespace std;
inline double map( double, double, double, double, double);

int main(){
    double num = 0, temp = 0, incremento = 0, porcentaje = 0;
    int tiempo = 0;
    cout << "Ingrese un numero: ";
    cin >> num;
    system("cls");

    cout << "\n Tiempo: "<< tiempo <<"\n\n" << porcentaje << "%";
    incremento = 256/num;
    temp = incremento;
    for(temp; temp < 256; temp += incremento){
        Sleep(1000);
        system("cls");
        tiempo ++;
        cout << "\n Tiempo: "<< tiempo <<"\n\n" << (porcentaje = map(temp, 0, 256, 0, 100)) << "%";
    }
     if(temp + incremento >= 256 && tiempo < num){
            Sleep(1000);
            system("cls");
            tiempo ++;
            temp = 255;
            cout << "\n Tiempo: "<< tiempo <<"\n\n" << (porcentaje = map(temp, 0, 255, 0, 100)) << "%";
        }
    system("pause");
}

inline double map( double X, double int_min, double int_max, double Out_min, double Out_max){
    return (X-int_min) * (Out_max-Out_min)/(int_max - int_min) + Out_min;
}