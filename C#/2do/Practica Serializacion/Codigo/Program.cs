using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Xml;
using System.Xml.Serialization;
using static System.Console;
using static System.Environment;
using static System.IO.Path;
using Figuras;

/*
    Carlos Daniel Lozano Vazquez 18300249 7A
    Practica serealizacion
    20/10/2021
*/

namespace Practica_Serializacion
{
    class Program
    {
        private static string path = Combine(CurrentDirectory, "CollectionFigures.xml");
        static void Main(string[] args)
        {

            var figuras = new List<Figuras1> { };

            char opc = ' ';
            while (opc != 'S')
            {
                WriteLine("Bienvenido a la Practica 2");
                WriteLine("Que quieres hacer: ");
                WriteLine("[1] Crear figuras");
                WriteLine("[2] Areas");
                WriteLine("[S] Salir");
                opc = ReadLine()[0];
                switch (opc)
                {
                    case '1':
                        CrearFiguras();
                        break;
                    case '2':
                        HacerCalculos();
                        break;
                    default:
                        WriteLine("gracias por participar");
                        break;
                }
            }

        }
        /// <summary>
        /// Metodo en el cual se selecciona que clase de figura crear e ingresarla
        /// a la lista.
        /// Aqui se serealiza al salir del menu, al igual que se hace un sort a la lista.
        /// </summary>

        public static void CrearFiguras()
        {
            char opc = ' ';
            uint[] indice = new uint[] { 0, 0, 0 };
            var listFiguras = new List<Figuras1> { };
            if (File.Exists(path))
            {
                File.Delete(path);
            }
            while (opc != 'S')
            {
                WriteLine("Que tipo de figura quieres hacer:");
                WriteLine("[1] Circulo");
                WriteLine("[2] Rectangulo");
                WriteLine("[3] Triangulo");
                WriteLine("[S] Salir");
                opc = ReadLine()[0];
                string figure = " ";
                uint num_fig = 0;

                switch (opc)
                {
                    case '1':
                        figure = "Circulos";
                        Circulo.index = indice[0];
                        ValNum(figure, out num_fig);
                        CreateC(ref listFiguras, num_fig);
                        indice[0] += num_fig;
                        break;
                    case '2':
                        figure = "Rectangulos";
                        Rectangulo.index = indice[1];
                        //var rec= new List<Rectangulo> { };
                        ValNum(figure, out num_fig);
                        CreateR(ref listFiguras, num_fig);
                        indice[1] += num_fig;
                        break;
                    case '3':
                        Triangulo.index = indice[2];
                        //var trian = new List<Triangulo> { };
                        figure = "Triangulos";
                        ValNum(figure, out num_fig);
                        CreateT(ref listFiguras, num_fig);
                        indice[2] += num_fig;
                        break;
                    case 'S':
                        WriteLine("\nVolviendo al menu principal...\n");
                        break;
                    default:
                        WriteLine("\n\n**Dato Erroneo**\a\n");
                        break;
                }

            }
            //organizar alfabeticamente la lista para serealizar de manera adecuada.
            List<Figuras1> SortedList = listFiguras.OrderBy(o => o.id).ToList();
            FileSer(SortedList);
        }
        /// <summary>
        /// Parte donde se ejecutan las funciones para deserealizar
        /// hacer la busqueda para obtner los calculos.
        /// Cuenta con un varios 2 menus para ingresar opciones para obtener determinadas areas
        /// </summary>
        public static void HacerCalculos()
        {
            if (File.Exists(path))
            {
                string type = "All";
                string id = " ";
                char opc = ' ';
                List<Figuras1> listDer = new List<Figuras1> { };
                while (opc != 'S')
                {
                    WriteLine("Bienvenido a la Practica 2");
                    WriteLine("Que quieres hacer: ");
                    WriteLine("[1] Todas las areas");
                    WriteLine("[2] Todas las areas por seccion");
                    WriteLine("[3] Areas por un id");
                    WriteLine("[S] Salir");
                    opc = ReadLine()[0];
                    id = " ";
                    switch (opc)
                    {
                        case '1':
                            type = "All";
                            WriteLine("\n\n\t\t Las areas son:\n\n");
                            break;
                        case '2':
                            char opc2 = ' ';
                            while (opc2 != 'S')
                            {
                                WriteLine("[1] Todas las areas de Circulos");
                                WriteLine("[2] Todas las areas de Rectangulos");
                                WriteLine("[3] Todas las areas de Triangulos");
                                WriteLine("[S] Salir");
                                opc2 = ReadLine()[0];
                                id = " ";
                                switch (opc2)
                                {
                                    case '1':
                                        type = "C";
                                        break;
                                    case '2':
                                        type = "R";
                                        break;
                                    case '3':
                                        type = "T";
                                        break;
                                    case 'S':
                                        WriteLine("\n\nSaliendo...\n");
                                        break;
                                    default:
                                        break;
                                }
                                listDer = FileDes(type, id);
                                printList(listDer, id);
                            }
                            break;
                        case '3':
                            type = "One";
                            WriteLine("\nIngrese el id\nEjemplo: Triangulo 1 -> T1, es decir, el primer triangulo ingresado tiene id T1\n\nID: ");
                            id = ReadLine();
                            break;
                        case 'S':
                            WriteLine("\n\nSaliendo...\n");
                            break;
                        default:
                            WriteLine("gracias por participar");
                            break;
                    }
                    if (opc != '2')
                    {
                        listDer = FileDes(type, id);
                        printList(listDer, id);
                    }

                }
            }
            else
            {
                WriteLine("\n\aPrimero debe crar el archivo");
            }

        }
        /// <summary>
        /// Valida la cantidad de objetos a crear por parte del usuario
        /// </summary>
        /// <param name="figure"> Figura a crear, tipo string ej Rectangulo, circulo, triangulo</param>
        /// <param name="num"> numero a asignar para la cantidad de figuras a crear, tipo uint</param>
        public static void ValNum(string figure, out uint num)
        {
            num = 0;
            WriteLine($"Cuantos {figure} vas a querer: ");
            while (!(uint.TryParse(ReadLine(), out num) && num > 0))
            {
                WriteLine("\n\a**No se aceptan valores no numericos o menores a 1**\n");
                WriteLine($"Cuantos {figure} vas a querer: ");
            }
        }
        /// <summary>
        /// Valida los lados/Radio a ingresar de cada figura
        /// </summary>
        /// <param name="num"> valor a asignar al objeto si es valido</param>
        /// <param name="lado"> imprimir el tipo de lado que es, Base, altura, lado o radio</param>
        public static void ValNum(out double num, string lado)
        {
            num = 0.00;

            WriteLine($"{lado}: ");

            while (!(double.TryParse(ReadLine(), out num) && num > 0.99))
            {
                WriteLine("\n\a**No se aceptan valores no numericos o menores a 0.99**\n");
                WriteLine($"{lado}: ");
            }
        }
        /// <summary>
        /// serealiza la lista en un archivo .Xml
        /// </summary>
        /// <param name="_list"> es la lista a serealizar, tipo list(figuras1)</param>
        public static void FileSer(List<Figuras1> _list)
        {
            var xs = new XmlSerializer(typeof(List<Figuras1>));
            using (Stream stream = File.Open(path, FileMode.OpenOrCreate, FileAccess.Write, FileShare.None))
            {
                xs.Serialize(stream, _list); //objeto que acabo de crear y el objeto
            }
        }

        /// <summary>
        /// Deserealiza el archivo .Xml según lo que se quiera buscar
        /// es decir, filtra la lista deserealizada por los valores que se quieren obtener
        /// </summary>
        /// <param name="type"></param>
        /// <param name="_id"></param>
        /// <returns></returns>
        public static List<Figuras1> FileDes(string type = "All", string _id = " ") //type = ALL or R or T or C or One
        {
            List<Figuras1> _list = new List<Figuras1> { };
            List<Figuras1> filterList = new List<Figuras1> { };
            var xs = new XmlSerializer(typeof(List<Figuras1>));
            using (Stream stream1 = File.Open(path, FileMode.Open, FileAccess.Read, FileShare.None))
            {
                _list = xs.Deserialize(stream1) as List<Figuras1>; //objeto que acabo de crear y el objeto
            }

            if (type != "All")
            {
                if (type != "One")
                {
                    _id = type;
                }

                foreach (var item in _list)
                {
                    if (item.id == _id && type == "One")
                    {
                        filterList.Add(item); //se filtra por 1 id
                        break;
                    }
                    if (type == "R" || type == "C" || type == "T") //se filtra por seccion
                    {
                        if (item.id[0] == _id[0])
                        {
                            filterList.Add(item);
                        }
                    }

                }

            }
            else
            {
                return _list; // se busco todas las areas
            }

            return filterList;
        }
        /// <summary>
        /// Crea objeto de tipo triangulo y los agrega a la lista
        /// </summary>
        /// <param name="list"> pase  por referencia de la lista para que se edite, tipo List(figuras1)</param>
        /// <param name="num">numero de objetos a crear, tipo uint</param>
        public static void CreateT(ref List<Figuras1> list, uint num)
        {
            double[] Lados = new double[3];
            for (uint cont = 0; cont < num; cont++)
            {

                WriteLine($"Ingrese los datos del Triangulo {cont + 1}");
                for (uint j = 0; j < 3; j++)
                {
                    string lado = ($"Lado {j + 1}");
                    ValNum(out Lados[j], lado);
                }
                if ((Lados[0] + Lados[1]) > Lados[2])
                {
                    Triangulo triangulo = new Triangulo(Lados);
                    triangulo.CalculateType();
                    list.Add(triangulo);
                }
                else
                {
                    WriteLine($"\n\n\a**Esto no es un triangulo valido**\n");
                    cont--;
                }

            }
        }
        /// <summary>
        /// Crea un objeto del circulo para agregarlo a la lista
        /// </summary>
        /// <param name="list"> pase  por referencia de la lista para que se edite, tipo List(figuras1)</param>
        /// <param name="num">numero de objetos a crear, tipo uint</param>
        public static void CreateR(ref List<Figuras1> list, uint num)
        {
            double _base = 0.00;
            double altura = 0.00;

            for (uint cont = 0; cont < num; cont++)
            {
                WriteLine($"Ingrese los datos del Rectangulo {cont + 1}");
                ValNum(out _base, "Base");
                ValNum(out altura, "Altura");
                Rectangulo rectangulo = new Rectangulo(_base, altura);
                list.Add(rectangulo);
            }

        }
        /// <summary>
        /// Crea un objeto del circulo para agregarlo a la lista
        /// </summary>
        /// <param name="list">pase  por referencia de la lista para que se edite, tipo List(figuras1)</param>
        /// <param name="num">numero de objetos a crear, tipo uint</param>
        public static void CreateC(ref List<Figuras1> list, uint num)
        {
            double radio = 0.00;

            for (uint cont = 0; cont < num; cont++)
            {
                WriteLine($"Ingrese los datos del Circulo {cont + 1}");
                ValNum(out radio, "Radio");
                Circulo rectangulo = new Circulo(radio);
                list.Add(rectangulo);
            }
        }
        /// <summary>
        /// Imprime la lista deserealizada, la cual también fue filtrada
        /// </summary>
        /// <param name="_list"> lista a iterar e imprimir según se requiere, tipo list de la clase figuras1 </param>
        /// <param name="_id">id para buscar un indice en especifico por ejemplo C1 -> circulo uno, tipo string</param>
        public static void printList(List<Figuras1> _list, string _id = " ")
        {
            foreach (var item in _list)
            {
                WriteLine($"Area {item.id} = {item.Area()}");
                if (item.id[0] == 'T')
                {
                    //Triangulo temp = item.Triangulo;
                    if(_id == item.id)
                    {
                        WriteLine($"Tipo de triangulo que es {item.id} = {((Triangulo)(item)).CalculateType()}\n");
                        break;
                    }
                    else
                    {
                        WriteLine($"Tipo de triangulo que es {item.id} = {((Triangulo)(item)).CalculateType()}\n");
                    }
                }
                else
                    Write("\n");
            }
        }
    }
}
