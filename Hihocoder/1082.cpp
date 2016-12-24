#include <iostream>
#include <string>
#include <algorithm> 
#include <cctype>

using namespace std;

int main() {
    string str, temp;
    const string s1 = "marshtomp";
    const string s2 = "fjxmlhx";
    
    string::size_type a = s1.size();
    string::size_type b = s2.size();
    while (getline(cin, temp)) {
        str = temp;
        transform(str.begin(),str.end(),str.begin(),::tolower);
        
        string::size_type pos = 0;
        while ((pos=str.find(s1,pos))!=string::npos) {
            str.replace(pos, a, s2);
            temp.replace(pos,a,s2);
            pos+=b;
        }
        cout << temp << endl;
    }
    
    return 0;
}