int sharpPitch = A0;
int sharpWammy = A1;

int BuzzerL = 5;
int BuzzerR = 6;

int pitch;
int wammy;

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
    pitch = analogRead(sharpPitch);

    //TODO Add Mapping
    wammy = analogRead(sharpWammy);

    if((pitch >= pitchMin && pitch <= pitchMax) && (wammy >= wammyMin && wammy <= wammyMax)){
        playTone(pitch, wammy);
    }else
    {
        stopTone();
    }
    ;

    //TODO if in zone play mario song
    if (false)
    {
        song(1);
    }
}

void playTone(int tonePitch, int toneWammy)
{
    tone(BuzzerL, tonePitch, toneWammy);
    tone(BuzzerR, tonePitch, toneWammy);
}

void stopTone()
{
    noTone(BuzzerL);
    noTone(BuzzerR);
}
