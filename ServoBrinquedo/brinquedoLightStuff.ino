#include <Servo.h>

Servo servo;
int rEye;
int lEye;
int servoPos = 90;

void setup()
{
    servo.attach(9);
    servo.write(servoPos);
}

void loop()
{
    rEye = analogRead(0);
    lEye = analogRead(1);

    rEye > lEye ? servoPos++ : servoPos--;
    if (servoPos > 180)
    {
        servoPos = 180;
    }
    if (servoPos < 0)
    {
        servoPos = 0;
    }

    servo.write(90);
}