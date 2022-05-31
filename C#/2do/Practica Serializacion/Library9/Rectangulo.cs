using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml.Serialization;


namespace Figuras
{
    public class Rectangulo : Figuras1
    {
        [XmlIgnore]//para no mostrarlo en el .Xml
        public static uint index {get; set;}
        [XmlAttribute("Base")]
        public double Base { get; set; }

        [XmlAttribute("Altura")]
        public double altura { get; set; }

        /// <summary>
        /// constructor vacio
        /// </summary>
        public Rectangulo()
        {

        }
        /// <summary>
        /// Constructor para definir su base y altura del rectangulo, además aumentar el index de los triangulos y saber en cual se va.
        /// </summary>
        /// <param name="_base"> base ingresada por el usuario, tipo double</param>
        /// <param name="_altura">altura ingresada por el usuario, tipo double</param>
        public Rectangulo( double _base, double _altura)
        {
            index++;
            this.Base = _base;
            this.altura = _altura;
            this.id = "R" + index;
        }
        /// <summary>
        /// Calcula el arera del rectangulo y la asigna a su propiedad correspondiente
        /// tambien regresa el valor
        /// </summary>
        /// <returns> regresa el area obtenida, tipo double</returns>
        public override double Area()
        {
            this.area = this.Base * this.altura;
            return this.area;
        }
        /// <summary>
        /// calcula el perimetro obtendio y lo asigna a la propiedad que le corresponde
        /// </summary>
        /// <returns>Regresa el perimetro calculado, tipo double </returns>
        public override double Perimetro()
        {
            this.perimetro = (this.Base * 2) + (this.altura * 2);
            return this.perimetro;
        }
        // public override void InIndex(string id)
        // {


        // }
        
    }
}