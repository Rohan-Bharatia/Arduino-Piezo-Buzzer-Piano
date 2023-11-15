#include <Arduino.h>
#include <pitches.h>

int pitchPin[8];
int piezoBuzzerPin = 13;
int pitch[8];

void setup()
{
  for(int i = 0; i < 8; i++)
  {
    for(int p = 3; p < 11; p++)
    {
      pitchPin[p] = i;
    }
    pitch[i] = analogRead(pitchPin[i]);
    
    pinMode(pitchPin[i], INPUT);
  }
  pinMode(piezoBuzzerPin, INPUT);
}

void playPitches(int min, int max)
{
  for(int p = min; p < max + 1; p += 30)
  {
    for(int i = 0; i < 8; i++)
    {
      if(pitch[i] == HIGH)
      {
        tone(piezoBuzzerPin, p);
      }
    }
  }
}

void loop()
{
  playPitches(140, 350);

  delay(5);
}
