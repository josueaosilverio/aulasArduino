

int pot;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    pot = analogRead(0) / 4;
    delay(50);
    Serial.println(pot);
}