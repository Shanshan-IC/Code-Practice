#include <iostream>
#include <cstring>
using namespace std;
int main() {
    string str;
    while (cin >> str) {
        int num = 0;
        for (int i=0; i<str.length(); i++) {
            num += str[i]-'0';
            if (num>9)
                num = num/10+num%10;
        }
        if (num==0) continue;
        cout << num << endl;
    }
    return 0;
}

