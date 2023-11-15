#include <Arduino.h>
#include <pitches.h>

const int pitchPin[8] = {3, 4, 5, 6, 7, 8, 9, 10};
const int piezoBuzzerPin = 13;
const int pitch[8];

void setup()
{ 
  for(int i = 0; i < 8; i++)
  {
    pinMode(pitchPin[i], INPUT);
  }
  pinMode(piezoBuzzerPin, INPUT);

  for(int i = 0; i < 8; i++)
  {
    pitch[i] = analogRead(pitchPin[i]);
  }
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
