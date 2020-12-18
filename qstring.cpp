#include <Arduino.h>

#include "qstring.h"

//	String q_string;
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


qstring::qstring()
{
  memset(this, 0, sizeof(qstring));
}


void qstring::get_args(String *str)
{
}

String qstring::get_arg(String arg_name)
{
	return arg_name;
}

bool qstring::has_arg(String arg_name)
{
	return 0;
}
