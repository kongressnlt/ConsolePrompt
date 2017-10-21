#include "Include2.h"

using namespace std;

class Process_Working
{
public:
	DWORD FindProcessIdByStr(string proc_name);
	bool Inject(DWORD pID, char * path); //loadlibA
};

