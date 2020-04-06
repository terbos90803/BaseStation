/**********************************************************************

  CurrentMonitor.h
  COPYRIGHT (c) 2013-2016 Gregg E. Berman

  Part of DCC++ BASE STATION for the Arduino

**********************************************************************/

#ifndef CurrentMonitor_h
#define CurrentMonitor_h

#include "Arduino.h"

#define  CURRENT_SAMPLE_SMOOTHING   0.01

#ifdef ARDUINO_AVR_UNO                        // Configuration for UNO
#define  CURRENT_SAMPLE_TIME        10
#else                                         // Configuration for MEGA    
#define  CURRENT_SAMPLE_TIME        1
#endif

class CurrentMonitor {
    static long int sampleTime;
    const int pin;
    const float maxSamples;
    const char * const msg;
    float current;
  public:
    CurrentMonitor(int pin, float maxSamples, const char *msg);
    static boolean checkTime();
    void check();
    int getUsedCurrent() // Returns the used portion of available current on a scale of 0-1024
    {
      return (int)(1024 * current / maxSamples);
    }
};

#endif
