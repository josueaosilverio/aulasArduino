
int timebtw;

void setup() {
  Serial.begin(9600);
  Serial.println("V1.1");
  timebtw=1000;
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(timebtw);
  digitalWrite(LED_BUILTIN, LOW);
  delay(timebtw);
   
    if (timebtw <= 0 && timebtw%2 == 0){
      timebtw += 51;
    }else if (timebtw < 1001 && timebtw%2 == 1){
      timebtw += 50;
    } else{
      timebtw -= 51;
    };

    Serial.print("Tempo: ");
    Serial.println(timebtw);
}
