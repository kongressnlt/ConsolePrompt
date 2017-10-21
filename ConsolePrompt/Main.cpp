#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>

#include "Custom_Class.h"
#include "aditionally.h"
#include "Process_Working.h"
#include "MemoryEngine.h"

using namespace std;

/*
Привет, данный проект кодил @alexuiop1337, не удаляй данный ватермарк хотя бы в знак уважения к проделанной работе.
К сожалению сюда не попал kewriteprocessmemory() и mmap, но ничего, сурс вы все же увидите, а так ждите byte4????
*/
const int cmds_count = 12;
string cmds[cmds_count] =
{
	"cmdlist - Shows all commands",
	"cat read <path to the file> - reads from file and shows it in console",
	"cat write <path to the file> <your string> - writes string to the file",
	"ls - info about application startup path folder",
	"echo <string> - shows your string in the console",
	"find - find strings by sub-strings",
	"find_proc_pid <string process name> - returns process's pID",
	"currentDateTime - shows string with current Date Time",
	"fileExists <string path> - shows true or false in order if file exists or not",
	"inject <method> <pid> <pth to a dll> - injects your dll into a process (methods: lla)",
	"clear - clearing console",
	"exit - closes app"
};

int main()
{
	string command;

	Custom_Class c_f;
	aditionally misc;
	Process_Working pw;
	
	cout << "cmdlist - for help" << endl;
	while (true)
	{
		cin >> command;
		if (command == "cmdlist")
		{
			for (int i = 0; i < cmds_count; i++)
			{
				cout << cmds[i] << endl;
			}
		}
		else if (command == "find")
		{
			string sub_com;
			cin >> sub_com;
			for (int i = 0; i < cmds_count; i++)
			{
				string res = c_f.find_by_substr(cmds[i], sub_com);
				res == "" ? (cout << res) : (cout << res << endl);
			}
		}
		else if (command == "find_proc_pid")
		{
			string proc_n;
			cin >> proc_n;
			cout << pw.FindProcessIdByStr(proc_n) << endl;
		}
		else if (command == "inject")
		{
			string sub_com;
			cin >> sub_com;
			if(sub_com == "lla")
			{
				string proc_n;
				cin >> proc_n;
				DWORD pid = pw.FindProcessIdByStr(proc_n);
				if (pid != 0)
				{
					string path;
					cin >> path;
					char * p = misc.convert_str_to_char(path);
					if (pw.Inject(pid, p))
					{
						c_f.echo("Injected!");
					}
					else
					{
						c_f.echo("Can't inject!");
					}
				}
				else
				{
					c_f.echo("Can't find a process! (" + proc_n + ")");
				}
			}
			else
			{
				c_f.echo("Can't find this method!");
			}
		}
		else if (command == "currentDateTime")
		{
			cout << misc.currentDateTime() << endl;
		}
		else if (command == "fileExists")
		{
			string path;
			cin >> path;
			misc.FileExists(path) ? (cout << "Exist" << endl) : (cout << "File doesn't exist" << endl);
		}
		else if (command == "cat")
		{
			string arg;
			cin >> arg;
			if (arg == "read")
			{
				string path;
				cin >> path;
				cout << "Readed: " << endl << c_f.cat_raw_read(path) << endl;
			}
			else if (arg == "write")
			{
				string path;
				cin >> path;
				string str;
				getline(cin, str);
				c_f.cat_raw_write(path, str);
			}
		}
		else if (command == "ls")
		{
			system("dir");
		}
		else if (command == "echo")
		{
			string sub_com;
			getline(cin, sub_com);
			c_f.Remove_First_Char(sub_com);
			c_f.echo(sub_com);
		}
		else if (command == "clear")
		{
			system("cls");
		}
		else if (command == "exit")
		{
			return 0;
		}
		else
		{
			cout << "Unknown command: " << command << endl;
		}
	}
	//6
	return 0;
}
