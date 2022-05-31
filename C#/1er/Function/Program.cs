using System;
using static System.Console;

namespace Function
{
    class Program
    {
        static void Main(string[] args)
        {
            //RunTimes();
           // RunCalculateTax();
           RunFibImperative();
        }
        #region functions
        /// <summary>
        /// function that takes number and print table in console
        /// </summary>
        /// <param name="number"> Byte type, so ... only between 0 and 255 </param>
        static void TimesTable(byte number){
            WriteLine($"esta es la tabla del {number}");
            for(int i = 1; i <= 12; i++){
                WriteLine($"{i} * {number} = {i * number}");
            }
            WriteLine();
        }
        /// <summary>
        /// 
        /// </summary>
        static void RunTimes(){
            bool isNumber = false;
            byte num = 0;
            while(!isNumber){
                Write("\n Ingrese un numero entre el 0 y 255\n\n Numero: ");
                isNumber = byte.TryParse(ReadLine(), out num);
            }
            TimesTable(num);
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="amount"></param>
        /// <param name="twoLetterRegionCode"></param>
        /// <returns></returns>
        static decimal CalculateTax(decimal amount, string twoLetterRegionCode){
            decimal rate = 0.0M;
            switch(twoLetterRegionCode)
            {
                case "CH":
                    rate= .16M;
                break;
                case "JL":
                case "MX":
                    rate = .18M;
                break;
                case "SO":
                    rate = 0.09M;
                break;
                default:
                rate = .12M;
                break;
            }
            return amount * rate;
        }
        
        static void RunCalculateTax(){
            Write("Enter amount: ");
            string amountIntText = ReadLine();
            Write("Ebtrer a two-letter region code: ");
            string region = ReadLine();
            if(decimal.TryParse(amountIntText, out decimal amount)){
                decimal textToPay = CalculateTax(amount, region);
                WriteLine($"You must pay {textToPay} in sales tax");
            }
            else{
                WriteLine("\n This is !isdigit, so is not a number");
            }
        }
       

        #endregion
    
        #region lambda expression
            static int FibImperative(int term){
                if (term == 1)
                {
                    return 0;
                }
                if(term == 2)
                return 1;
                else
                return FibImperative(term-1) + FibImperative(term-2);
            }

            static void RunFibImperative(){
                for (int i = 1; i <= 15; i++)
                {
                    WriteLine($"The {i} term of Fibonacci sequence is {FibImperative(term: i)}");
                }
            }
        #endregion
    }
}
