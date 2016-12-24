/* 1.2 Implement a function void reversefchar* str) in Cor C++ which reverses a null-terminated
string. */

#include <string>
#include <iostream>

using namespace std;

void swap(char &a, char&b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}

void reverse(char* str)
{
	int n = strlen(str);
	
	for (int i = 0; i < n; i++)
		swap(str[i], str[n - i - 1]);
}

int main() {
	char s[] = "1234567890";
	reverse(s);
	cout << s << endl;
	return 0;
}