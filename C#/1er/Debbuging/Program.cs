using System;
using static System.Console;
using System.Diagnostics;

namespace Debbuging
{
    class Program
    {
        static void Main(string[] args)
        {
            double a = 4.5;
            double b = 2.5;
            double answer = Add(a, b);
            WriteLine($"{a} + {b} = {answer}"); //externalTerminbal para debugear con input
        }

        static double Add(double a, double b){
            return a + b;
        }
    }
}
