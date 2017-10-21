#include "aditionally.h"
#include <time.h>

/* Public */
const string aditionally::currentDateTime()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%d-%m-%Y %X", &tstruct);

	return buf;
}

char * aditionally::convert_str_to_char(string str)
{
	char* p = new char[str.size() + 1];
	strcpy(p, str.c_str());
	return p;
}


