#include "Custom_Class.h"

Custom_Class::Custom_Class()
{
}


Custom_Class::~Custom_Class()
{
}

/* Public */

void Custom_Class::echo(string str)
{
	cout << str << endl;
}

void Custom_Class::Remove_First_Char(string &str)
{
	string res;
	for (int i = 1; i < int(str.length()); i++)
	{
		res += str[i];
	}
	str = res;	
}

string Custom_Class::cat_raw_read(string path)
{
	ifstream is(path);
	vector<string> res;
	if (is.is_open())
	{
		string temp;
		while (is.good())
		{
			getline(is, temp);
			res.push_back(temp + "\n");
		}
		is.close();
		return sum_str_elems(res);
	}
	else
	{
		return "File doesn't exist!";
	}
}

void Custom_Class::cat_raw_write(string path, string letter)
{
	ofstream os(path);
	if (os.is_open())
	{
		Remove_First_Char(letter);
		os << letter;
	}
	else
	{
		echo("File doesn't exists!");
	}
	os.close();
}

string Custom_Class::find_by_substr(string str, string find_s)
{
	string res = "";
	try
	{
		size_t pos = str.find(find_s);
		if (pos == string::npos)
		{
			return res = "";
		}
		else
		{
			res = str.substr(pos);
			return res;
		}
	}
	catch (int i)
	{
		return res;
	}
}

/* Private */

string Custom_Class::sum_str_elems(vector<string> vec)
{
	string res = "";
	for (int i = 0; i < vec.size(); i++)
	{
		res += vec[i];
	}
	return delete_from_index(res, res.length() - 1);
}

string Custom_Class::delete_from_index(string str, int index)
{
	string res = "";
	for (int i = 0; i < index; i++)
	{
		res += str[i];
	}
	return res;
}