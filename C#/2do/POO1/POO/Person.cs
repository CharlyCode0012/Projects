using System;
using System.Collections.Generic;
using System.Xml.Serialization;

namespace Shared
{
    public class Person
    {
        //fileds = stored data, privados -> encapsulacion
        //Constant = 
        //Read - only
        //Events


        //Methods
        //Constructor
        //Property
        //Indexer
        //Operator
        //
        [XmlAttribute("Fname")]
        public string FirstName  { get; set; }
        [XmlAttribute("Lname")]
        public string LastName { get; set; }
        [XmlAttribute("DoB")]
        public DateTime DateOfBirth {get; set;}
        //public FavoriteFood FavoriteFood;

        public HashSet<Person> Children {get; set;}

        protected decimal Salary { get; set; }
        public readonly DateTime Instantied;

          public Person (decimal initSalary)
        {
            Salary = initSalary;
        }
        public Person()
        {

        }

        public Person( string initialName, string initialHomePlanet) 
        {
            FirstName = initialName;
            Instantied = DateTime.Now;
        }


        // tuple
        public (string Name, int Number) GetFruit(){
            return ("Apples", 5);
        }

        //paso por referencia
        public void PassingParameters(int x, ref int y, out int z)
        {
            //**value**
            //Saca una copìa del valor, es decir, pasa el valor explicitamente

            //**ref**
            //Obtiene la referencia de la varaible, y si sufre una modificacion aqui
            //esta tambien se modifica la original

            //out
            //out only, el valor comienza en el metodo y lo regresa al "main"
            z = 10;
            x++;
            y++;
            z++;
        }
    }
}
