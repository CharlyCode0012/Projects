#include<TimerOne.h>
#define Led1 52
#define Led2 53
#define button 2

int cont = 0, val = 0;
static boolean output1 = LOW, output2 = LOW;
void timeIn();
void timeEx();

void setup() 
{
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(button, INPUT_PULLUP); 
  Timer1.initialize(1000000);      //Configura el TIMER en 1 Segundo
  Timer1.attachInterrupt(timeIn);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
}

void loop() 
{
  if(digitalRead(button)== LOW)
      timeEx();
}

void timeIn()
{
  cont ++;
  if (cont%5 == 0){
      output1 = !output1;
      digitalWrite(Led1, output1); 
  }   
}
void timeEx()
{
  
  val++;
  if (val%30 == 0){
      output2 = !output2;
      digitalWrite(Led2, output1);
  }
}
