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
String in_str="// GET /?qw=1&wr=2 HTTP/1.1", out;
int start_ind;
char ch_ch;
int ch_i;
char buf[100];

void setup() 
{
	Serial.begin(9600);



Serial.println("started");
	//qs_o.get_args(&in_str);

//in_str.charAt(0)="s";
	qs_o.get_args(&in_str);




out= qs_o.args_name[0];
out.toCharArray(buf, out.length());
Serial.println(out);

ch_ch='a';
out+= ch_ch;
out.toCharArray(buf, out.length());
Serial.println(out);
ch_ch='s';
out+= ch_ch;
out.toCharArray(buf, out.length());
Serial.println(out);


	
out=String(qs_o.args_cnt);
out.toCharArray(buf, out.length());
Serial.println(out);


out=qs_o.args_name[0];
out.toCharArray(buf, out.length());
Serial.println(out);

ch_ch='a';
qs_o.args_name[0]+= ch_ch;
ch_ch='s';
qs_o.args_name[0]+= ch_ch;


out=qs_o.args_name[1];
out.toCharArray(buf, out.length());
Serial.println(out);

out=qs_o.args_val[0];
out.toCharArray(buf, out.length());
Serial.println(out);

out=qs_o.args_val[1];
out.toCharArray(buf, out.length());
Serial.println(out);

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	qs_o.args_name[0]+= 'n';
	qs_o.args_name[0]+= 'o';
	qs_o.args_name[0]+= 'p';


	  	  Serial.println("qs_o.args_name");
	  Serial.println(qs_o.args_name[0]);


	  
	  Serial.println("args_cnt");
	  Serial.println(qs_o.args_cnt);
	  Serial.println("get_arg(wr)");
	  Serial.println(qs_o.get_arg("wr"));
	  Serial.println("get_arg(qw)");
	  Serial.println(qs_o.get_arg("qw"));
	  Serial.println("has_arg(wr)");
	  Serial.println(qs_o.has_arg("wr"));
	  Serial.println("has_arg(qwe)");
	  Serial.println(qs_o.has_arg("qwe"));

}



void loop()
{


}

