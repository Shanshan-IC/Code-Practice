#include <string>
#include <iostream>

using namespace std;
/* 1.1 Implement an algorithm to determine if a string has all unique characters. What if
you cannot use additional data structures? */

//If it is ASCII character
// O(N)
bool isUniqueChar(const string& str)
{
	int length = str.length();
	if (length > 256)
		return false;

	//create a boolean array, if it appears twice, then return false
	bool a[256];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < length; i++)
	{
		int v = (int)str[i];
		if (a[v])
			return false;
		a[v] = true;
	}
	return true;
}



