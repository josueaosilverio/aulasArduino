
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
   
    if(timebtw > 200 && timebtw%2 == 0){
      timebtw -= 100;
    }else if (timebtw <= 200 && timebtw%2 == 0){
      timebtw += 101;
    }else if (timebtw < 1501 && timebtw%2 == 1){
      timebtw +=100;
    } else{
      timebtw -= 101;
    };

    Serial.print("Tempo: ");
    Serial.println(timebtw);
}
