#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    freopen("E:/A-large-practice.in","r",stdin);
    freopen("E:/A-large-practice.out","w",stdout);
    int T, N;
    string s;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << "Case #" << i + 1 << ": ";
        cin >> N;
        int count = 0;
        string res = "";
        for (int j = 0; j <= N; j++) {
            getline(cin, s);
            set<char> charS;
            for (char c: s)
                if (isalpha(c))
                    charS.insert(c);
            if (charS.size() > count) {
                count = charS.size();
                res = s;
            } else if (charS.size() == count) {
                if (s.compare(res) < 0)
                    res = s;
            }
        }
        cout << res << endl;
    }
    return 0;
}