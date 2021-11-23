const byte buzzer_pin = 9;

void setup()
{
    pinMode(buzzer_pin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    if (Serial.available()>0)
    {
        char buzzer_picked = Serial.read();
        int buzzer_freq = Serial.parseInt();
        write_freq(buzzer_picked, buzzer_freq);
    }
}

void write_freq(char buzzer, int frequency)
{
    if (buzzer == 'f')
    {
        tone(buzzer_pin, frequency);
        return;
    }
    
    return;
}
