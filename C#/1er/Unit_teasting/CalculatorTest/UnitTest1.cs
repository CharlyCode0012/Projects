using System;
using Xunit;
using CalculatorLib;

namespace CalculatorTest
{
    public class UnitTest1
    {
        [Fact]
        public void TestingAdd2And2()
        {
            //Arranged
            double a = 2;
            double b = 2;
            double expected = 4;
            //Act
            var calc = new Calculator();
            double actual = calc.Add(a,b);
            //Assert
            Assert.Equal(expected, actual);
        }

        [Fact]
        public void TestingAdd2And3(){
            //Arranged
            double a = 2;
            double b = 3;
            double expected = 5;
            //Act
            var calc = new Calculator();
            double actual = calc.Add(a,b);
            //Assert
            Assert.Equal(expected, actual);
        }

        [Fact]
        public void TestingAdd5And100(){
            //Arranged
            double a = 5;
            double b = 100;
            double expected = 105;
            //Act
            var calc = new Calculator();
            double actual = calc.Add(a,b);
            //Assert
            Assert.Equal(expected, actual);
        }
         [Fact]
        public void TestingAdd1And9(){
            //Arranged
            double a = 1;
            double b = 9;
            double expected = 10;
            //Act
            var calc = new Calculator();
            double actual = calc.Add(a,b);
            //Assert
            Assert.Equal(expected, actual);
        }
    }
}
