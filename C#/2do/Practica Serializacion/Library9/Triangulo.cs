using System;
using System.Collections.Generic;
using System.Xml.Serialization;
using System.Linq;
namespace Figuras
{
    public class Triangulo : Figuras1
    {   
        [XmlIgnore]
        public static uint index {get; set;}
        [XmlAttribute("Lados")]
        public double[] Lados { get; set; }
        [XmlAttribute("Tipo_de_triangulo")]
        public string trianguloTipo {get; set; } 
        public Triangulo() 
        { 
            //index++;
            //this.id = "T" + index;
        }
        /// <summary>
        /// constructor que genara los lados del triangulo y aumenta el index
        /// </summary>
        /// <param name="_lados"> son los lados ingresados por el usuario, arreglo tipo double</param>
        public Triangulo(double[] _lados)
        {
            index++;
            int index1 = 0;
            this.Lados = new double[] { 0, 0, 0 };
            foreach (double item in _lados)
            {
                this.Lados.SetValue(item, index1++);
            }
            this.id = "T" + index;
        }
        /// <summary>
        /// calcula el area por medio de la formula de heron, se requiere del perimetro para ello
        /// </summary>
        /// <returns>regresa el area calculada</returns>
        public override double Area()
        {
            double semiP = Perimetro()/2; // se obtiene le semiperimetro para la formula
            this.area = Math.Sqrt(semiP * (semiP-Lados[0]) * (semiP - Lados[1]) * (semiP - Lados[2]) );
            return this.area;
        }
        /// <summary>
        /// Calcula el perimetro del triangulo, el cual sera importante para sacara el area
        /// </summary>
        /// <returns>regresa el perimetro</returns>
        public override double Perimetro()
        {
            foreach(double item in Lados)
            {
                this.perimetro += item;
            }
            return this.perimetro;
        }
        /// <summary>
        /// calcula el tipo de triangulo que es, tanto de angulos como por sus lados
        /// </summary>
        /// <returns>regresa el tipo de dato calculado, tipo string</returns>
        public string CalculateType()
        {
            double cPow2 = (Lados[2] * Lados[2]);
            double bPow2 = (Lados[1] * Lados[1]);
            double aPow2 = (Lados[0] * Lados[0]);
            string tipoLados = "";
            string tipoAngulos = "";
            foreach(var item in Lados.GroupBy(t => t).Where(t => t.Count() != 0))
            {
                if(item.Count() == 3)
                    tipoLados = "Equilatero";
                else{
                        if(item.Count() == 2)
                        {
                            tipoLados = "Isoseles";
                        }
                        if(item.Count() == 1)
                        {
                            tipoLados = "Escaleno";
                        }
                    }
                
            }
            //se emplea el teorema de pitagoras para obtener su tipo de angulo
            if(cPow2 == (bPow2 + aPow2))
                tipoAngulos = "es Rectancgulo";
            if(cPow2 < (bPow2 + aPow2))
                tipoAngulos = "es Acutangulo";
            if(cPow2 > (bPow2 + aPow2))
                tipoAngulos = "es Obstusangulo";
            
            trianguloTipo = "Es un triangulo " + tipoLados + " y tambien " + tipoAngulos;
            this.trianguloTipo = "Es un triangulo " + tipoLados + " y tambien " +tipoAngulos;
            return trianguloTipo;
        }
    }
}