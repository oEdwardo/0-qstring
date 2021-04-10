#ifndef QSTRING_H
#define QSTRING_H

#include <stdint.h>

//#if ARDUINO >= 100
#include <Arduino.h>       // for delayMicroseconds, digitalPinToBitMask, etc
//#else
//#include "WProgram.h"      // for delayMicroseconds
//#include "pins_arduino.h"  // for digitalPinToBitMask, etc
//#endif

#define MAX_ARGS 10

class qstring {
  public:
	qstring();
	
	String qstring_str;
	String args_name[MAX_ARGS];
	String args_val[MAX_ARGS];

	int args_cnt;

    void get_args(String* str); // fills args_name/args_val
    String get_arg(String arg_name); // from int arr
    bool has_arg(String arg_name); // from int arr
};
#endif // QSTRING_H
