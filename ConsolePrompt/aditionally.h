#pragma once
#include "Include.h"
#include <io.h>
using namespace std;
class aditionally
{
public:
	const string currentDateTime();
	bool FileExists(string path)
	{
		return _access(path.c_str(), 0) != -1;
	}
	char * convert_str_to_char(string str);
};

