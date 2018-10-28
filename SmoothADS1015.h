#include "Arduino.h"
#include <Adafruit_ADS1015.h>

class SmoothADS1015
{
  private:
    // unsigned int analog_pin;
    unsigned int npos[4];
    unsigned int *pos[4];
    unsigned int Npos[4];
    Adafruit_ADS1015 *ads;
  public:
    SmoothADS1015();
    ~SmoothADS1015();
    void setup(unsigned int _pin, unsigned int _Npos);
    int read(unsigned int _pin);
};
