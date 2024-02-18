int pot1= A0;
int pot2=A1;
int motor1=6;
int motor2=5;
int switch2=12;
int switch1=13; 
char t;
void setup()
{
 pinMode(pot1,INPUT);
 pinMode(pot2,INPUT);
 pinMode(switch1,INPUT); 
 pinMode(switch2,INPUT);  
 pinMode(motor2,OUTPUT);
 pinMode(motor1,OUTPUT);
 Serial.begin(9600);
}

void loop()
{
  if (Serial.available()){
  t=Serial.read();
  Serial.println(t);}
  
  
  
 if(digitalRead(switch1)==1&& t=='L')
 {
   analogWrite(motor1,analogRead(pot1));
 }
 else if (digitalRead(switch2)==1 && t=='R')
  {
    analogWrite(motor2,analogRead(pot2));
  }     
 else if (digitalRead(switch2)==1&& digitalRead(switch1)==1&& t=='S')
 {
   analogWrite(motor2,0);
   analogWrite(motor1,0);
 } 
 else if (digitalRead(switch2)==0&& digitalRead(switch1)==0) 
 {
  analogWrite(motor2,0);
   analogWrite(motor1,0);
 }
  
}