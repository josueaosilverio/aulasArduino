
int timebtw;

void setup() {
  Serial.begin(9600);
  Serial.println("V1.2");
  timebtw=1000;
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(timebtw = (timebtw <= 0 && timebtw%2 == 0) ? timebtw += 51 : (timebtw < 1001 && timebtw%2 == 1) ? timebtw += 50 : (timebtw <=1000 && timebtw%2==0) ? timebtw -= 50 : timebtw -= 51);
}
