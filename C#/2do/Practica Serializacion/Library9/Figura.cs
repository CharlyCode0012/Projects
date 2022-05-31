using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml.Serialization;
using static System.Math;


namespace Figuras
{
    //clase "abstracta" para poder tener herencia un mejor control de los datos.
    public  class Figuras1
    {
        [XmlAttribute("ID")]
        public string id{ get; set;}
        [XmlIgnore]
        public double area { get; set; }
        [XmlIgnore]
        public double perimetro { get; set; }
        
        public Triangulo Triangulo;
        public Circulo Circulo;
        public Rectangulo Rectangulo;
        public Figuras1()
        {
        }
        public virtual double Area()
        {
            return 0.0;
        }
        public virtual double Perimetro()
        {
            return 0.0;
        }

    }
}
