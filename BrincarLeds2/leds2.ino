int potR;
int potB;
int potG;



void setup()
{
  Serial.begin(9600);
  Serial.println('V1.0');
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  potR = analogRead(0)/4;
  potB = analogRead(1)/4;
  potG = analogRead(2)/4;
  analogWrite(9, potR);
  analogWrite(10, potB);
  analogWrite(11, potG);

}