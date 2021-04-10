#include <Arduino.h>

#include "qstring.h"

//	String q_string;
/*
class qstring
{
  public:
	qstring();

	String qstring_str;
	String args_name[MAX_ARGS];
	String args_val[MAX_ARGS];
	int args_cnt;

    void get_args(String *str);
    String get_arg(String arg_name);
    bool has_arg(String arg_name);
};
*/
#define syms_limit 100

qstring::qstring()
{
  memset(this, 0, sizeof(qstring));
}


void qstring::get_args(String* qstr)
{
    int str_sym_idx= 0; //, field_sym_idx= 0; // field_sym_idx = name or val field
    int arg_idx= 0;
    char ch;
    bool name_field_flg= 1, filled=0;

	args_cnt=0;
	
	// find "GET /?"
	str_sym_idx= (*qstr).indexOf("GET /?")+6;


	args_name[0]="";
	args_val[0]="";

	while (arg_idx < syms_limit)
	{ 	ch= (*qstr).charAt(str_sym_idx); 

		if (ch==0x3d) // '\='
		{	name_field_flg=0;
			//field_sym_idx= 0;
			str_sym_idx++;
			continue;
		}
		if (ch==0x26) // '\&'
		{	//field_sym_idx= 0;
			name_field_flg=1;
			str_sym_idx++;

			if (filled) 
			{	arg_idx++;
				args_name[arg_idx]="";
				args_val[arg_idx]="";
	        	filled=0;
			}
			continue;
		}
		if (ch==0x20) // '\ '
		{	
			if (filled) 
			{	arg_idx++;
				args_name[arg_idx]="";
				args_val[arg_idx]="";
	        	filled=0;
			}
			break;
		}

        if (name_field_flg==1)
        {	args_name[arg_idx]+= ch;
        	filled= 1;
        }
        else
        {	args_val[arg_idx]+= ch;
        }

    	//field_sym_idx++;
		str_sym_idx++;
	}
	args_cnt= arg_idx;
}

String qstring::get_arg(String arg_name)
{
    int i;
    for (i=0; i<args_cnt; i++)
    {	if (args_name[i]==arg_name) 
    	{	return (args_val[i]);
    	}
    }
   	return "";
}

bool qstring::has_arg(String arg_name)
{
    int i;
    for (i=0; i<args_cnt; i++)
    {	if (args_name[i]==arg_name) 
    	{	return (1);
    	}
    }
	return 0;
}
