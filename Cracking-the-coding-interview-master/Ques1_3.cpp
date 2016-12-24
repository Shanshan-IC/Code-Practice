#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/* Given two strings, write a method to decide if one is a permutation of the other. */
//method one: sort and compare them
bool permutation(const string&a, const string& b)
{
	//copy string
	string str_a(a);
	string str_b(b);

	if (str_a.length() != str_b.length())
		return false;
	sort(str_a.begin(), str_a.end());
	sort(str_b.begin(), str_b.end());
	
	int len = str_a.length();

	for (int i = 0; i < len; i++)
	{
		if (str_a[i] != str_b[i])
			return false;
	}
	return true;
}

//method two:calculate the times of character
bool permutation2(const string&a, const string& b)
{
	if (a.length() != b.length())
		return false;
	int asciss_C[256] = { 0 };
	int len = a.length();
	for (int i = 0; i < len; i++)
	{
		int val = static_cast<int>(a[i]);
		asciss_C[val]++;
	}

	for (int i = 0; i < len; i++)
	{
		int val = static_cast<int>(b[i]);
		if ((--asciss_C[val]) < 0)
			return false;
	}

	return true;
}