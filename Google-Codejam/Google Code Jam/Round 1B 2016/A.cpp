#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    freopen("C:\\Users\\Administrator\\Downloads\\A-small-practice.in","r",stdin);
    freopen("C:\\Users\\Administrator\\Downloads\\A-small-attempt0.out","w",stdout);
    string a[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    string ordered[] = {"0", "2", "4", "6", "8", "3", "5", "1", "7", "9"};
    string t = "ZWUXGHFOVI";
    int num;
    cin >> num;
    string str;
    for (int i = 0; i < num; i++) {
        string res = "";
        cout << "Case #" << i + 1 << ": ";
        cin >> str;
        int map[26] = {0};
        for (int i = 0; i<str.size(); i++)
            map[(int)(str[i]-'A')]++;
        for (int i = 0; i < 10; i++) {
            while (map[(int)(t[i]-'A')]) {
                res += ordered[i];
                int temp = stoi(ordered[i]);
                for (int j = 0; j < a[temp].size(); j++)
                    map[(int)a[temp][j]-'A']--;
            }
        }
        sort(res.begin(), res.end());
        cout << res << endl;
    }
    return 0;
}