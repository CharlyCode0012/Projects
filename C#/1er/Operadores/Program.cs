using System;
using System.IO;
using static System.Console;


namespace Operadores
{
    class Program
    {
        static void Main(string[] args)
        {
            //unarios
            #region operadores unarios
            int a = 0;
            int b = a++; //asigna el valor actual de "a" (0) y luego "a" aumenta 1
            --b;
            b++;
            #endregion

            #region operadores binarios
            // +
            // -
            // *
            // /
            // %
            #endregion

            #region Asignacion
            a += 3;
            a -= 3;
            a *= 3;
            a /= 3;
            a = 6;
            #endregion

            #region operadores logicos
            //operan en valores booleanos
            bool c = true, d = false;
            WriteLine($"AND |c |d");
            WriteLine($"c |{c & c, -5} | {c & d, -5}");
            WriteLine($"d |{d & c, -5} | {d & d, -5}");
            WriteLine($"OR |c |d");
            WriteLine($"c |{c | c, -5} | {c | d, -5}");
            WriteLine($"d |{d | c, -5} | {d | d, -5}");
            WriteLine($"XOR |c |d");
            WriteLine($"c |{c ^ c, -5} | {c ^ d, -5}");
            WriteLine($"d |{d ^ c, -5} | {d ^ d, -5}");
            #endregion

            #region opeadores condicionales

            #endregion

            #region operadores binarios
            //int e = 10; //0000 1010
            //int f = 6; // 0000 0110
            #endregion

            #region Pattern matching if
                object o = 3;
                int j = 4;
                if(o is int i){
                    WriteLine($"{i} x {j} = {i * j}");
                }else{
                    WriteLine("o no es un int asi que no se puede multiplicar");
                }

            #endregion

            #region Switch pattern matching
                string path = @"D:\Ceti\7mo\Porgramacion avanzada\1er\Operadores";
                WriteLine("Press R for readonly or W for Write");
                ConsoleKeyInfo Key = ReadKey();
                WriteLine();
                Stream s = null;

                if(Key.Key == ConsoleKey.R){
                    s = File.Open(
                        Path.Combine(path, "file.txt"),
                        FileMode.OpenOrCreate,
                        FileAccess.Read
                    );
                }else{
                    s = File.Open(
                        Path.Combine(path, "file.txt"),
                        FileMode.OpenOrCreate,
                        FileAccess.Write
                    );
                }
                string message = string.Empty;
                switch(s){
                    case FileStream writeable when s.CanWrite:
                        message = "The stream is a file that i can write to";
                        break;
                    case FileStream readOnlyFile:
                        message = "The stream is a file a read-only";
                        break;
                    case MemoryStream ms:
                        message = "The stream is a memory address";
                        break;
                    case null:
                        message = "The stream is null";
                        break;
                    default:
                        message = "The stream is some other type";
                        break;
                }
                WriteLine(message);
            #endregion

            #region simplified swtich
                message = s switch
                {
                    FileStream writeable when s.CanWrite
                        =>"The stream is a file that i can write to",
                    FileStream readOnlyFile
                        =>"The stream is a file a read-only",
                    MemoryStream ms
                        =>"The stream is a memory address",
                    null
                        =>"The stream is null",
                    _  
                        =>"The stream is some other type"
                };
            #endregion

            #region FOREACH
            string[] names = {"Zurdo, Akali, Charlie"};
            foreach(var name in names){
                WriteLine($"{name} tiene {name.Length} caracteres");
            }
            #endregion

            #region 
            #endregion

            #region 
            #endregion
        }
        private static bool DoStuff(){
            WriteLine("I am doing some stuff");
            return true;
        }
    }
}
