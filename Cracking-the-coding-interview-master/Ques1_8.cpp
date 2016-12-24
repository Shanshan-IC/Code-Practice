/* 1.8 Assume you have a method isSubstring which checks if one word is a substring
of another. Given two strings, si and s2, write code to check Ifs2 is a rotation of si
using only onecalltoisSubstring (e.g., "waterbottLe" is a rotation of "erbottLewat").*/

#include <string>
#include <iostream>

using namespace std;

bool isSubstring(string s1, string s2)
{
	if (s1.find(s2) != string::npos)
		return true;
	return false;
}

bool isRotation(string s1, string s2)
{
	if (s1.length() != s2.length() || s1.length() < 0)
		return false;
	return isSubstring(s1 + s1, s2);
}