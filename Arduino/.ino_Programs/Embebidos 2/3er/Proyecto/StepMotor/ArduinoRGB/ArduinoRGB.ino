#include <CheapStepper.h>
#include <TimerOne.h>

CheapStepper stepper( 8, 9, 10, 11);
String respuesta, velocidad, dir, state;
int coma = 0, coma1 = 0, estado = 0, ms, miliS = 0;

void Move();
String find_S(int, int);

void render()
{
  respuesta = Serial1.readStringUntil('\n');
  Serial.println(respuesta);
  Serial1.flush();
  Timer1.initialize(1000);
  Timer1.attachInterrupt(Move);
  coma = respuesta.indexOf(',');
  coma1 = respuesta.indexOf(',', coma + 1);
}

void setup(){
  stepper.setRpm(10); 
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop(){
  while (Serial1.available() == 0){}
    
  render();
  state = find_S(respuesta.length(), coma1+2);
  estado = state.toInt();
  if(state.length() > 0)
  {
        while(estado == 1)
      {
          render();
          state = find_S(respuesta.length(), coma1+2);
          velocidad = find_S(coma, 0);
          dir = find_S(coma1, coma + 2);
          while(state.length() <= 0)
          {
            render();
            state = find_S(respuesta.length(), coma1+2);
            velocidad = find_S(coma, 0);
            dir = find_S(coma1, coma + 2);
          } 
          estado = state.toInt();
          
          ms = map(velocidad.toInt(), 1, 100, 50000, 500);
          Timer1.initialize(ms);
          if(velocidad == "0")
            stepper.stop();
      }
        
        if(state.toInt() == 0)
        {
          stepper.stop();
        }
        //delay(ms);
        Serial.println(velocidad + " - " + dir + " - " + state); 
   }
      
   delay(100);
  
}


String find_S(int indice, int inicio){
  String data = "";
  for(int cont = inicio; cont < indice; cont++)
  {
     data += respuesta[cont];
  }
  return data;
}

void Move()
{
  bool Clock = (dir == "Izquierda")? true : false;
  if(dir.length() > 0 && velocidad != "0" && state != "0" && miliS == 10)
  {
    stepper.moveDegrees(Clock, 30);
    miliS=0;
  }  
   else
   {
    if(miliS<10)
    {
      miliS++;
    } 
   }
}
