using System;
using System.IO;
using System.Text;
using static System.Console;
using static System.IO.Directory;
using static System.IO.Path;
using static System.Environment;
/*
    Carlos Daile Lozano vazquez 18300249 7A
    13/10/2021
    Practica de archivos
*/


namespace Practica_Archivos
{
    class Program
    {
        static void Main(string[] args)
        {
            WorkWithFiles();
        }
        static void WorkWithFiles(){
            string info;

            var dir = Combine(GetFolderPath(SpecialFolder.Personal), "Code", "OutputFiles");
            CreateDirectory(dir);
            string textFile = Combine(dir, "Dummy.txt");
            string backUpFile = Combine(dir, "Dummy.bak");
            WriteLine($"Working with: {textFile}");
            //check if file exist
            WriteLine($"Does is exist? {File.Exists(textFile)}");

            //crea el archivo .text y escribe sobre el
            StreamWriter textWriter = File.CreateText(textFile);
            textWriter.WriteLine("Hola Danny OwO");
            textWriter.Close();

            //alamcena el path del archivo .bak
            var f1 = new FileInfo(backUpFile);

            //se almacena en una string el contenido del archivo .text
            StreamReader textReader = File.OpenText(textFile);
            info = textReader.ReadToEnd();
            textReader.Close();

            //ciclo para alidar el estado del archivo .bak y controlar excepciones
            while(IsFileLocked(f1, info)){
                WriteLine("Archivo abierto");
            }
            //se elimina el .text
            DropFileText(textFile);

            //se crea un objeto para leer el archivo .bak
            StreamReader textReadBak = new StreamReader(backUpFile);
            WriteLine("La informacion del archivo .bak es: " + (textReadBak.ReadToEnd()));
            textReadBak.Close();
        }
        
        /// <summary>
        /// esta funcion se encarga de eliminar el archivo especificado
        /// </summary>
        /// <param name="textPath"> esta es la direcciona relativa del archivo, sirve para saber su uubicacion, tipo string </param>
        static void DropFileText(string textPath){
            File.Delete(textPath);
        }

        /// <summary>
        /// controla algunas de las excepciones que se pueden causar por un archivo.
        /// </summary>
        /// <param name="file"> sirve para ubicar el archivo (direccion de este), es del tipo FileInfo</param>
        /// <param name="text"> cadena de texto a copiar en el archivo especificado, tipo string</param>
        /// <returns></returns>
        static bool IsFileLocked(FileInfo file, string text)
        { 

            FileStream stream = null;

            try
            {
                using(stream = file.Open(FileMode.OpenOrCreate, FileAccess.Write, FileShare.None)){
                    UnicodeEncoding uniecoding = new UnicodeEncoding();
                    byte[] result = uniecoding.GetBytes(text);
                    stream.Write(result, 0, uniecoding.GetByteCount(text));
                    stream.Close();
                }
            }
            catch (IOException)
            {
                // el archivo no está disponible porque:
                 // todavía se está escribiendo 
                 // o esta siendo procesado por otro hilo
                 // o simplemente no existe (ya ha sido procesado)
                return true;
            }
            finally
            {
                if (stream != null)
                stream.Close();
            }

            //file is not locked
            return false;
        }
    }  
}


 