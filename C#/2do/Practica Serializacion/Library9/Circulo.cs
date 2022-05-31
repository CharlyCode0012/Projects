using System;
using System.Collections.Generic;
using System.Xml.Serialization;
using System.Linq;

namespace Figuras
{
    public class Circulo : Figuras1
    {
        [XmlIgnore]
        public static uint index {get; set;}
        [XmlAttribute("Radio")]
        public double radio { get; set; }
        public Circulo()
        {

        }

        /// <summary>
        /// Constructor para crar un circulo con un radio
        /// además de que se aumenta en 1 un index para saber en que figura estamos
        /// </summary>
        /// <param name="_radio"></param>
        public Circulo( double _radio)
        {
            index++;
            this.radio = _radio;
            this.id = "C" + index;
        }
        /// <summary>
        /// sobreescribe la funcion base, para calcular el area del circulo
        /// </summary>
        /// <returns>regresa el area del circulo, tipo double</returns>
        public override double Area()
        {
            this.area = Math.PI * radio * radio;
            return this.area;
        }
        /// <summary>
        /// sobreescribe la funcion base, para calcular el primetro del circulo
        /// </summary>
        /// <returns>regresa el perimetro del circulo, tipo double</returns>
        public override double Perimetro()
        {
            this.perimetro = this.radio*2 * Math.PI;
            return this.perimetro;
        }
    }
}