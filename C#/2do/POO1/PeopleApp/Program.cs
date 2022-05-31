using System;
using Shared;
using System.Collections.Generic;
using System.Xml.Serialization;
using System.IO;
using static System.Environment;
using static System.IO.Path;
using static System.Console;

namespace PeopleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            // var zurdo = new Person();
            // zurdo.FirstName = "zurdito UwU";
            // zurdo.DateOfBirth = new DateTime(1960, 12, 22);
            // zurdo.FavoriteFood = FavoriteFood.Tacos;
            // WriteLine($"\n\n{zurdo.FirstName} was worn on {zurdo.DateOfBirth: d MMMM yyyy}\n Comida favorita: {zurdo.FavoriteFood}");
            
            // zurdo.Children.Add(new Person {FirstName = "Zurdito"});
            // zurdo.Children.Add(new Person {FirstName = "Derecha"});
            // WriteLine($"{zurdo.FirstName} has {zurdo.Children.Count} children");

            // /*for (int child = 0; child < zurdo.Children.Count; child++)
            // {
            //     WriteLine($" {zurdo.Children[child].Name} ");
            // }*/

            // var Camila = new Person
            // {
            //     FirstName = "Camila Zalasar",
            //     DateOfBirth = new DateTime(1998, 3 , 7)
            // };

            // WriteLine($"\n\n{Camila.FirstName} was worn on {Camila.DateOfBirth: d MMMM yyyy}\n");

            // #region Using Bank
            //     BankAccount.InterestRate = 0.016M;
            //     //static var carlosAccount = new BankAccount();
            //     var asafAccount = new BankAccount();
            //     asafAccount.AccountName = "Mr. Asaf";
            //     asafAccount.Balance = 2400M;
            //     //asafAccount.BankAccount.InterestRate = 0.021M;
            //     WriteLine($"{asafAccount.AccountName} earned {asafAccount.Balance * BankAccount.InterestRate} interest");

            // #endregion

            // #region Value by default
            //     var blankPerson = new Person();
            //     WriteLine($"{blankPerson.FirstName} was created at {blankPerson.HomePlanet} on a {blankPerson.Instantied}");

            // #endregion

            // #region using tuples
            //     (string Name, int Number) fruit = Camila.GetFruit(); 
            //     // o usar 
            //     //var fruit = Camila.GetFruit()
            //     WriteLine($"{fruit.Name}, {fruit.Number}");
            //     //experimentar con 2 clases en una tupla **FIRMA DE UNA FUNCION
            // #endregion

            // #region Pointer
            //     int a = 10;
            //     int b = 20;
            //     int c = 30;
            //     WriteLine($"Before**\n\n a: {a} b: {b} c: {c}\n");
            //     zurdo.PassingParameters(a, ref b, out c);
            //     WriteLine($"After**\n\n a: {a} b: {b} c: {c}\n");
            //     //zurdo.AnotherPartial = 10;
            // #endregion

            #region Serialize
                var people = new List<Person>
                {
                    new Person (30000M)
                    {
                        FirstName = "RO",
                        LastName = "El billullo",
                        DateOfBirth = new DateTime(1990, 3, 14)
                    },

                    new Person (20000M)
                    {
                        FirstName = "Danny",
                        LastName = "Lozano",
                        DateOfBirth = new DateTime(2003, 3, 14),
                        Children = new HashSet<Person>
                        {
                            new Person(0M)
                            {
                                FirstName = "Danielito",
                                LastName = "Lozanito UwU",
                                DateOfBirth = new DateTime(2001, 12, 25)
                            }
                        }
                    }
                };

                var xs = new XmlSerializer(typeof(List<Person>)); //tipo de objeto a serealizar
                string path = Combine(CurrentDirectory, "people.xml");
                
                using(FileStream stream = File.Create(path))
                {
                    xs.Serialize(stream, people); //objeto que acabo de crear y el objeto
                }

            #endregion
        }
    }
}
