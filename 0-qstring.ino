/*
 *  This sketch demonstrates how to set up a simple HTTP-like server.
 *  The server will set a GPIO pin depending on the request
 *    http://server_ip/gpio/0 will set the GPIO2 low,
 *    http://server_ip/gpio/1 will set the GPIO2 high
 *  server_ip is the IP address of the ESP8266 module, will be 
 *  printed to Serial when the module is connected.
 */
/*
class qstring
{
  public:
	String qstring_str;
	String args_arr[MAX_ARGS];
	String args_val[MAX_ARGS];

	qstring();

    void get_args(String *str);
    String get_arg(String arg_name);
    bool has_arg(String arg_name);
};
*/

#include <Arduino.h>
#include "qstring.h"

qstring qs_o;

float f_val = 123.6794;
String in_str="// GET /?q=1&w=2 HTTP/1.1";
int start_ind;

void setup() 
{
	Serial.begin(9600);

	qs_o.get_args(&in_str);
}



void loop()
{


}

