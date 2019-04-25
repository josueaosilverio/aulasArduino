const int sharpPitchR = A0;
const int sharpPitchL = A1;

const int BuzzerL = 5;
const int BuzzerR = 6;

int pitchR;
int pitchL;

int counter;

void setup()
{
    pitchL = 0;
    pitchR = 0;
    counter = 0;
    Serial.begin(9600);
    Serial.println("V1.2");
    pinMode(BuzzerL, OUTPUT);
    pinMode(BuzzerR, OUTPUT);
}

void loop()
{

    pitchR = analogRead9010(pitchR, analogRead(sharpPitchR));
    pitchL = analogRead9010(pitchL, analogRead(sharpPitchL));

    Serial.print("R:");
    Serial.println(pitchR);
    Serial.print("L:");
    Serial.println(pitchL);


    
    if (counter % 2 == 0)
        if ((pitchR < 110))
        {
            noTone(BuzzerR);
        }
        else
        {
            noTone(BuzzerL);
            tone(BuzzerR, pitchR);
        };
    if (counter % 2 == 1)
        if ((pitchL < 110))
        {
            noTone(BuzzerL);
        }
        else
        {
            noTone(BuzzerR);
            tone(BuzzerL, pitchL);
        };

    counter++;
}

int analogRead9010(int oldVal, int newVal)
{
    return round((0.9 * oldVal) + (0.1 * newVal));
};

int analogReadAvg(int pin, int samples)
{
    int values[samples];
    int avg;
    for (int i = 0; i < samples; i++)
    {
        values[i] = analogRead(pin);
    }
    for (int i = 0; i < samples; i++)
    {
        avg += values[i];
    }

    avg = avg / samples;

    return avg;
};