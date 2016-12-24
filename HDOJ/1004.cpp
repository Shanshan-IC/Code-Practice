#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    string str;
    unordered_map<string, int> m;
    while (cin >> n) {
        int max = 0;
        string res;
        while (n--) {
            cin >> str;
            m[str]++;
            if (m[str]>max) {
                max = m[str];
                res = str;
            }
        }
        if (max == 0)   continue;
        else    cout << res << endl;
        m.clear();
    }
    return 0;
}

