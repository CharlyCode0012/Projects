using System;
using static System.Console;

/******************************************************************************

Los derechos de autor de este codigo corresponden a Carlos Daniel Lozano Vazquez

2021/08/16

Alumno del plantel Ceti Colomos
Registro 18300249
******************************************************************************/

namespace Variables
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
            //varibales para imprimir
            string typeText = "Tipo", numberBytes = "Byte(s) de memoria", max = "MAX", min = "MIN";
            WriteLine("----------------------------------------------------------------------------------------");
            //el numero que esta e lado de la variable es el numero de caracteres que tomara en cuenta y el signo ya sea para empezar de izquierda o derecha
            WriteLine($"{typeText, -14} {numberBytes, -12} {min, 22} {max, 31}");
            WriteLine("----------------------------------------------------------------------------------------");
            //se usa el operador sizeof para obtener el numero de byte(s) que necesita el tipo de dato
            //MinValue y MaxValue son propiedades/campos para obtener los valores limites de ese tipo de dato
            WriteLine ($"{"sbyte", -14} {sizeof(sbyte), -10} {sbyte.MinValue, 31} {sbyte.MaxValue, 30}");            
            WriteLine ($"{"byte", -14} {sizeof(byte), -10} {byte.MinValue, 31} {byte.MaxValue, 30}");            
            WriteLine ($"{"short", -14} {sizeof(short), -10} {short.MinValue, 31} {short.MaxValue, 30}");            
            WriteLine ($"{"ushort", -14} {sizeof(ushort), -10} {ushort.MinValue, 31} {ushort.MaxValue, 30}");            
            WriteLine ($"{"int", -14} {sizeof(int), -10} {int.MinValue, 31} {int.MaxValue, 30}");            
            WriteLine ($"{"uint", -14} {sizeof(uint), -10} {uint.MinValue, 31} {uint.MaxValue, 30}");            
            WriteLine ($"{"long", -14} {sizeof(long), -10} {long.MinValue, 31} {long.MaxValue, 30}");            
            WriteLine ($"{"ulong", -14} {sizeof(ulong), -10} {ulong.MinValue, 31} {ulong.MaxValue, 30}");            
            WriteLine ($"{"float", -14} {sizeof(float), -10} {float.MinValue, 31} {float.MaxValue, 30}");            
            WriteLine ($"{"double", -14} {sizeof(double), -10} {double.MinValue, 31} {double.MaxValue, 30}");            
            WriteLine ($"{"decimal", -14} {sizeof(decimal), -10} {decimal.MinValue, 31} {decimal.MaxValue, 30}");            
        }
    }
}
