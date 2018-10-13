int red1 = 10;
int green1 = 7;
int red2 = 8;
int green2 = 12;
int IR1 = A1;
int IR2 = A0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(red1,OUTPUT);
pinMode(green1,OUTPUT);
pinMode(red2,OUTPUT);
pinMode(green2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("A1=");
  Serial.println(analogRead(A1));
  Serial.print("A0=");
  Serial.println(analogRead(A0));
digitalWrite(red1,HIGH);
digitalWrite(green1,LOW);
digitalWrite(red2,HIGH);
digitalWrite(green2,LOW);
delay(1000);

if((analogRead(A1) & analogRead(A0))>400)
{
  digitalWrite(red1,LOW);
  digitalWrite(green1,HIGH);
  digitalWrite(red2,LOW);
  digitalWrite(green2,HIGH);
  delay(5000);
}
else if((analogRead(A1)>400) & (analogRead(A0)<400))
{
  digitalWrite(red1,LOW);
  digitalWrite(green1,HIGH);
  delay(5000);
  digitalWrite(red2,LOW);
  digitalWrite(green2,HIGH);
  delay(1000);
}
else if((analogRead(A1)<400) & (analogRead(A0)>400))
{
  digitalWrite(red1,LOW);
  digitalWrite(green1,HIGH);
  delay(1000);
  digitalWrite(red2,LOW);
  digitalWrite(green2,HIGH);
  delay(5000);
}
else
{
  digitalWrite(red1,LOW);
  digitalWrite(green1,HIGH);
  digitalWrite(red2,LOW);
  digitalWrite(green2,HIGH);
  delay(1000);
}
}
