#ifndef qstring_h
#define qstring_h

#include <stdint.h>

//#if ARDUINO >= 100
#include <Arduino.h>       // for delayMicroseconds, digitalPinToBitMask, etc
//#else
//#include "WProgram.h"      // for delayMicroseconds
//#include "pins_arduino.h"  // for digitalPinToBitMask, etc
#endif

class qstring
{
  public:
	String qstring_str;

	qstring();

    void get_args(String *str);
    String arg(String arg_name);
    bool hasArg(String arg_name);
};

#endif // qstring_h
