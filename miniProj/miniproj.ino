int sharpPitch = A0;
int sharpWammy = A1;

int BuzzerL = 5;
int BuzzerR = 6;

int pitch = 0;
int wammy = 0;

//TODO CALIBRATION
int pitchMin;
int pitchMax;

//TODO CALIBRATION
int wammyMin;
int wammyMax;

void setup()
{
    Serial.begin(9600);
    Serial.println("V1.2");
    pinMode(BuzzerL, OUTPUT);
    pinMode(BuzzerR, OUTPUT);
}

void loop()
{
    //TODO Add Mapping
    //pitch = analogRead10(sharpPitch);
    pitch = analogRead8020(pitch, analogRead(sharpPitch));

    //TODO Add Mapping
    //wammy = analogRead8020(sharpWammy);

    //playTone(pitch, wammy);

    Serial.println(pitch);
    tone(BuzzerR, pitch);

    //Serial.println(wammy);

    /*if((pitch >= pitchMin && pitch <= pitchMax) && (wammy >= wammyMin && wammy <= wammyMax)){
        playTone(pitch, wammy);
    }else
    {
        stopTone();
    }
    ;
*/
    //TODO if in zone play mario song
}

void playTone(int tonePitch, int toneWammy)
{
    tone(BuzzerL, tonePitch);
    delay(toneWammy);
    noTone(BuzzerL);
    tone(BuzzerR, tonePitch);
    delay(toneWammy);
    noTone(BuzzerR);
}

void stopTone()
{
    noTone(BuzzerL);
    noTone(BuzzerR);
}

int analogRead8020(int oldVal, int newVal)
{
    return round((0.9 * oldVal) + (0.1 * newVal));
};

int analogRead10(int pin)
{
    int values[10];
    int avg;
    for (int i = 0; i < 10; i++)
    {
        values[i] = analogRead(pin);
    }
    for (int i = 0; i < 10; i++)
    {
        avg += values[i];
    }

    avg = avg/10;
    if (avg < 0)
    {
        avg = avg*-1;
    }

    return avg;
};