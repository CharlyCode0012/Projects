using System;
using static System.Console;
/* 
    Propiedad de Carlos Daniel Lozano Vazquez
    18300249
    14/09/2021
    --Examen 1er Parcial PA 7A

*/
namespace Examen
{
    class Program
    {
        static void Main(string[] args)
        {

            //se cambia el texto de la terminal a blanco
            ForegroundColor = ConsoleColor.White;
            //El fondo de la terminal se cambia a gris oscuro
            BackgroundColor = ConsoleColor.DarkGray;
            //esta impresión más que nada es por mera cuestion estetica
            WriteLine();
            //variables para manejar el arreglo, o los datos ingresados
            int longitud = 0;
            string validar = string.Empty;

            WriteLine("\n Digite el tamaño del arreglo: ");
            validar = ReadLine();
            //tryParse para validar el tipo de dato
            bool success = int.TryParse(validar, out longitud);

            // entra si succes es true, es decir que longitud es entero y en el rango de 1 al 1000
            if(success && longitud > 0 && longitud < 1001)
            {
                //creacion del arreglo 
                int[] arr = new int[longitud];
                // num_R almacena el numero random creado, sum es para poner un numero con signo contrario a ese valor y la suma de 0
                int num_R = 0, sum = 0;

                //objeto random
                var rand = new Random();

                //for para ingresar los datos al arreglo
                for(int i = 0; i < longitud-1; i++){
                    num_R = rand.Next(-1000, 1000);
                    sum+= num_R;
                    arr[i] = num_R;
                }
                arr[longitud-1] = -sum;
                Write("\n El arreglo es: \n [");

                //for para imprimir
                foreach(int item in arr){
                    Write(item + ", ");
                }
                Write("] ");
            }
            else
            {
                //rango incorrecto o simplemente no es un int
                WriteLine("Error de datos");
            }
        }


    }
}
