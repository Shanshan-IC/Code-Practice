#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/* Write a method to replace all spaces in a string with '%20'.You may assume that the
string has sufficient space at the end of the string to hold the additional characters,
and that you are given the "true" length of the string.*/

char* replace(char *c)
{
	if (c == NULL)
		return NULL;
	int len = strlen(c);
	int count = 0;
	//calculate the number of space
	for (int i = 0; i < len; i++)
		if (c[i] == ' ')
			count++;
	//new string
	int p = 0;
	char *cc = new char[len + 2 * cnt + 1];
	for (int i = 0; i < len; i++)
	{
		if (c[i] == ' ')
		{
			cc[p] = '%';
			cc[p + 1] = '2';
			cc[p + 2] = '0';
		}
		else
		{
			cc[p] = c[i];
			p++;
		}
	}
	cc[p] = '\0';
	return cc;
}
