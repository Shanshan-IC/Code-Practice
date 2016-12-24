#include <string>
#include <iostream>
#include <sstream>

using namespace std;

/*1.5 Implement a method to perform basic string compression using the counts of
repeated characters. For example, the string aabcccccaaa would become
a2blc5a3. If the "compressed" string would not become smaller than the original
string, your method should return the original string.*/

string compress(string str)
{
	int len = str.length();
	if (len <= 1)
		return str;
	int count = 1;
	char temp = str[0];
	ostringstream out;
	for (int i = 1; i < len; i++)
	{
		if (str[i] != temp)
		{
			out << temp << count;
			count = 0;
			temp = str[i];
		}
		count++;
	}

	out << temp << count;
	string res = out.str();
	if (res.length() > str.length())
		return str;
	return res;
}