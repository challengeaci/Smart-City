
int IR1 = A1;
int IR2 = A0;
int led1 = 3;
int led2 = 5;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
 Serial.println("Sensor 1=");
 Serial.println(analogRead(A1));
 Serial.println("Sensor 2=");
 Serial.println(analogRead(A0)); 
 
 int val=analogRead(A2);

 Serial.println(val);
 if(val>600){
  
digitalWrite(led1,HIGH);
 
  analogWrite(led1,255/10);

  digitalWrite(led2,HIGH);
     analogWrite(led2,255/10);
  
  if(analogRead(A1)<300)
  {
    digitalWrite(led1,HIGH);
    analogWrite(led1,255/10);
  }
  else
  {
    digitalWrite(led1,HIGH);
  }

  if(analogRead(A0)<300)
  {
    digitalWrite(led2,HIGH);
    analogWrite(led2,255/10);
  }
else
  {
    digitalWrite(led2,HIGH);
  }
 }
 else
 {
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
 }
  
  }
