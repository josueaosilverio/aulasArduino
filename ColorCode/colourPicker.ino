int R;
int G;
int B;

void setup()
{
    Serial.begin(9600);
    pinMode(6, INPUT_PULLUP);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}

void loop()
{
    if (digitalRead(6) == LOW)
    {
        digitalWrite(3, HIGH);
        delay(100);        
        B = map(analogRead(0), 0, 1023, 255, 0);
        delay(100);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        delay(100);        
        G = map(analogRead(0), 0, 1023, 255, 0);
        delay(100);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        delay(100);        
        R = map(analogRead(0), 0, 1023, 255, 0);        
        delay(100);
        digitalWrite(5, LOW);
        Serial.print("rgb(");
        Serial.print(R);
        Serial.print(",");
        Serial.print(G);
        Serial.print(",");
        Serial.print(B);
        Serial.println(")");
    }
    
}