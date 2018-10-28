# CRead ADS1015 with sliding average smoothing.

# Methods:

SmoothADS1015();  // setup object

void setup(unsigned int _pin, unsigned int _Npos);	// setup one of the 4 analog inputs (_pin=0-3) with a specific sliding window width (_Npos)
   
int read(unsigned int _pin);	// Read averaged analog value from one of the 4 analog inputs (_pin=0-3)
