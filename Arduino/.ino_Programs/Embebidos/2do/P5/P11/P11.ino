#define LED 3 
#define POT A0  // pin al que se ha conectado el potenciometro
 
int raw_pot; // almacenar el valor del potenciometro
bool flag = true; 
int duty, temp;   // ciclo util de la PWM
 
void setup() {
  // apago el motor poniendo el pin en estado bajo
  Serial.begin(9600);
  pinMode(LED, OUTPUT);   
  digitalWrite( LED, LOW );
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
  
  raw_pot = analogRead(POT);
  duty = map(raw_pot, 0, 1023, 0, 255); // mapeo el valor de la lectura al rango 0-255
  analogWrite( LED, duty );     // actualizar ciclo de trabajo  
  if(duty  !=  temp  ||  (duty  ==  0  &&  flag  ==  true))
  {
    Serial.print("Potenciometro: ");
    Serial.println(duty); 
    flag = false;
    temp = duty; 
  } 
  delay(30);
}
