#include "SmoothADS1015.h"

SmoothADS1015::SmoothADS1015()
{
  ads = new Adafruit_ADS1015();
  ads->setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  ads->begin();
  delay(10);
}

SmoothADS1015::SmoothADS1015(int SDA, int SCL)
{
  ads = new Adafruit_ADS1015();
  ads->setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads->begin();
  Wire.begin(SDA,SCL);
  delay(10);
}

SmoothADS1015::~SmoothADS1015()
{
  for (int n=0; n<4; n++)
    delete[] pos[n];
  delete ads;
}

void SmoothADS1015::setup(unsigned int _pin, unsigned int _Npos)
{
  Npos[_pin] = _Npos;
  npos[_pin] = 0;
  pos[_pin] = new unsigned int [Npos[_pin]];
  for (int n=0; n<Npos[_pin]; n++)
    pos[_pin][n] = ads->readADC_SingleEnded(_pin);
}

int SmoothADS1015::read(unsigned int _pin)
{
  pos[_pin][npos[_pin]] = ads->readADC_SingleEnded(_pin);
  npos[_pin] = (npos[_pin]+1) % Npos[_pin];
  unsigned int current_pos = 0;
  for (int n=0; n<Npos[_pin]; n++)
    current_pos += pos[_pin][n];
  return int(round(float(current_pos)/float(Npos[_pin])));
}
