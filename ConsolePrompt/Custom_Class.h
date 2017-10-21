#include "Include.h"

using namespace std;

class Custom_Class
{
public:
	Custom_Class();
	~Custom_Class();
	void echo(string str);
	void Remove_First_Char(string &str);
	string cat_raw_read(string path);
	void cat_raw_write(string path, string letter);
	string find_by_substr(string str, string find_s);

	/* May be useful*/
	template<class T>
	void echo_vector(vector<T> vec)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << endl;
		}
	}

	template<class T>
	T sum_of_vec(vector<T> vec)
	{
		T res;
		for (int i = 0; i < vec.size(); i++)
			res += vec[i];
		return res;
	}

private:
	string sum_str_elems(vector<string> vec);
	string delete_from_index(string str, int index);
};

