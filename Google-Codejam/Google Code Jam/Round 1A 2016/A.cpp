#include <iostream>
using namespace std;

int main() {
    freopen("C:\\Users\\Administrator\\Downloads\\A-large-practice.in","r",stdin);
    freopen("C:\\Users\\Administrator\\Downloads\\A-large-attempt0.out","w",stdout);
    int num;
    cin >> num;
    string s;
    for (int i=0; i<num; i++) {
        cout << "Case #" << i+1 << ": ";
        cin >> s;
        string res = "";
        res += s[0];
        for (int i=1; i<s.size(); i++) {
            if (s[i]>=res[0]) res = s[i] + res;
            else    res = res + s[i];
        }
        cout << res << endl;
    }
    return 0;
}