#include "Process_Working.h"


DWORD Process_Working::FindProcessIdByStr(string proc_name)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processSnapshot == INVALID_HANDLE_VALUE)
		return 0;

	Process32First(processSnapshot, &processInfo);
	if (!proc_name.compare(processInfo.szExeFile))
	{
		CloseHandle(processSnapshot);
		return processInfo.th32ProcessID;
	}

	while (Process32Next(processSnapshot, &processInfo))
	{
		if (!proc_name.compare(processInfo.szExeFile))
		{
			CloseHandle(processSnapshot);
			return processInfo.th32ProcessID;
		}
	}

	CloseHandle(processSnapshot);
	return 0;
}

bool Process_Working::Inject(DWORD pID, char * path)
{
	HANDLE proc_handle;
	LPVOID RemoteString;
	LPVOID LoadLibAddy;
	if (pID == 0)
	{
		return false;
	}
	proc_handle = OpenProcess(PROCESS_ALL_ACCESS, false, pID);
	if (proc_handle == 0)
		return false;
	LoadLibAddy = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");
	RemoteString = VirtualAllocEx(proc_handle, NULL, strlen(path), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	WriteProcessMemory(proc_handle, RemoteString, path, strlen(path), NULL);
	CreateRemoteThread(proc_handle, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryA, RemoteString, NULL, NULL);
	CloseHandle(proc_handle);
	return true;	
}