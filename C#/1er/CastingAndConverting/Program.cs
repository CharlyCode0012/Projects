using System;
using static System.Console;
using static System.Convert;

namespace CastingAndConverting
{
    class Program
    {
        static void Main(string[] args)
        {
            #region Casting
            //Implicit casting
            int a = 10;
            double b = a;
            //Explicit Casting
            decimal c = 5.8M;
            int d = (int)c;   
            #endregion

            #region Convert
            double g = 9.81;
            int h = ToInt32(g); //redondea por sistema britanico
            WriteLine($"G is {g} and h is {h}");

            double [] doubles = new [] {9.49, 9.5, 9.51, 10.49, 10.5, 10.51};
            foreach(double item in doubles){
                WriteLine($"ToInt({item}) is {ToInt32(item)} ");
            }
            foreach(double item in doubles){
                WriteLine(format: "Math.Round({0}, 0, MidpointRounding.AwayFromZero) is {1}", 
                    arg0: item, 
                    arg1: Math.Round(value: item, digits: 0, mode:MidpointRounding.AwayFromZero)
                );
            }
            #endregion

            #region Converting To String
                int number = 12;
                WriteLine(number.ToString());
                bool boolean = true;
                WriteLine(boolean.ToString());
                object me = new object();
                WriteLine(me.ToString());
            #endregion    

            #region Binary to String
                //128 bytes
                byte[] binaryObject = new byte[128];
                (new Random()).NextBytes(binaryObject);
                WriteLine("Binary Object as bytes: ");
                for(int i = 0; i < binaryObject.Length; i++){
                    Write($"{binaryObject[i]:X} ");
                }
                WriteLine();
                string encoded = ToBase64String(binaryObject);
                WriteLine("Binary object as Base 64 " + encoded);
            #endregion

            #region Parse
                int age = int.Parse("18");
                DateTime birthday = DateTime.Parse("2 Janury 2003");


                //Try parse
                int count = 0;
                string input = string.Empty;
                bool isnumber = false;
                do 
                {
                    isnumber = int.TryParse(input, out count);
                }while(!isnumber);
            #endregion
        }
    }
}
