int soundSensor = A0;
int LED = 3;

void setup() 
{

  pinMode (soundSensor, INPUT);
  pinMode (LED, OUTPUT);
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop()
{
  int statusSensor = 0;
  statusSensor = analogRead (soundSensor);
  Serial.println(statusSensor);
  if (statusSensor <= 50)
  {
    digitalWrite(8, HIGH);
    digitalWrite(3, LOW);   
    digitalWrite(4, LOW);   
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW);   
    digitalWrite(7, LOW); 
    delay(75);
  }
  if(statusSensor <= 52 && statusSensor >= 50)
  {
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(3, LOW);   
    digitalWrite(4, LOW);   
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW); 
    delay(75);  
  }
  if(statusSensor <= 54  && statusSensor >= 52 )
  {
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(3, LOW);   
    digitalWrite(4, LOW);   
    digitalWrite(5, LOW); 
    delay(500);    
  }
  if(statusSensor <= 55  && statusSensor >= 54)
  {
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(3, LOW);   
    digitalWrite(4, LOW);  
    delay(75);  
  }
    if(statusSensor <= 56 && statusSensor >= 55)
  {
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    delay(75); 
  }
    if(statusSensor >= 56)
  {
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    delay(75); 
  }

}
