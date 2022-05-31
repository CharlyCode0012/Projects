using System;
using System.Collections;
using System.Collections.Generic;
using static System.Console;


namespace Examen
{
    class Program
    {
        static void Main(string[] args)
        {

            string texto = string.Empty;
            char opc = ' ';
            string msg = ($"\t\t\t ~~MENU~~\n\n{"A.- Verificar balanceo de parentesis de un texto",-2} \n{"S.- Salir",-2}\n\n Opcion:");
            while (opc != 'S')
            {
                bool noBalanceado = false;
                opc = Char.ToUpper(GetKeyPress(msg, new char[] { 'A', 'S' }));
                switch (opc)
                {
                    case 'A':
                        WriteLine("\n Cadena: ");
                        while (!noBalanceado)
                        {
                            texto = ReadLine();
                            int valPar = valSigno(texto, '(', ')');
                            int valCor = valSigno(texto, '[', ']');
                            int valLla = valSigno(texto, '{', '}');

                            if (valPar == -1 || valCor == -1 || valLla == -1)
                            {
                                noBalanceado = false;
                                Write($"\a\n Cadena de texto invalida, favor de ingresar otra...\n\n Cadena: ");
                            }
                            else
                            {
                                WriteLine($"\a\n Cadena de texto balanceada, bien hecho \n");
                                noBalanceado = true;
                            }
                        }

                        break;
                    case 'S':
                        WriteLine($"\n\n Saliendo...\n");
                        break;

                }
            }

        }
        /// <summary>
        /// este metodo sirve para validar que la cadena tenga su respectivos caracteres de abieto y cerrado
        /// se hace por medio de una pila ya que es una estrcuctura eficiente para este tipo de problemas
        /// LIFO
        /// </summary>
        /// <param name="_texto">cadena de texto a evaluar, tipo string</param>
        /// <param name="abSigno">signo de abierto a buscar, tipo char</param>
        /// <param name="ciSigno">signo de cerrado a busacr, tipo char</param>
        /// <returns>regresas 1 si la cadena pasa, si manda -1 es que hubo algun error</returns>
        public static int valSigno(string _texto, char abSigno, char ciSigno)
        {
            Stack pila = new Stack();

            foreach (char item in _texto)
            {   //el caracter es identico a uno de estos simbolos ( { [
                if (item == abSigno)
                {
                    pila.Push(item);
                }
                //en caso de que no haya algún contenido es que no hay signo de apertura
                if (item == ciSigno)
                {
                    if (pila.Count != 0)
                    {
                        //se quita el unico dato de la pila
                        pila.Pop();
                    }
                    else
                    {
                        return -1;//cadena invalida
                    }
                }

            }
            if (pila.Count == 0)
            {
                return 1;//cadena correcta
            }
            else
            {
                return -1;
            }
                
        }
        /// <summary>
        /// Este metodo sirve para detectar que tecla se esta presonando del teclado 
        /// y regresar su valor en caracter para ser evaluado
        /// es un evento
        /// </summary>
        /// <param name="msg">mensaje a escibir en la terminal, tipo string</param>
        /// <param name="validChars">arreglo de chars que queremos que sea la tecla apretada, tipo char[]</param>
        /// <returns>regresa el carcater tecleado</returns>
        private static Char GetKeyPress(String msg, Char[] validChars)
        {
            ConsoleKeyInfo keyPressed;
            bool valid = false;

            Console.Write(msg);
            do
            {
                Console.Write(msg);
                keyPressed = Console.ReadKey();
                Console.WriteLine();
                if (Array.Exists(validChars, ch => ch.Equals(Char.ToUpper(keyPressed.KeyChar))))
                    valid = true;
            } while (!valid);
            return keyPressed.KeyChar;
        }
    }
}
