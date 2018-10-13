int trigPin=4;
int echoPin=2;
void setup() {
  // put your setup code here, to run once:
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
  Serial.begin(115200);
  Serial.println("AT+CIPMUX=0");
  delay(1000);

}

void loop() {
 digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
int duration = pulseIn(echoPin, HIGH);
long distance= duration*0.034/2;
Serial.println(distance);
  Serial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80");
  delay(100);
  if(Serial.find("Error")){return;}
  String cmd="GET /update?api_key=6XT3SUY8TD0B5M1D&field1="+String(distance);
  cmd=cmd+"\r\n\r\n";
  Serial.println("AT+CIPSEND="+String(cmd.length()));
  if (Serial.find(">")){Serial.println(cmd);}
  else{Serial.println("AT+CIPCLOSE");}
  delay(8000);

}
