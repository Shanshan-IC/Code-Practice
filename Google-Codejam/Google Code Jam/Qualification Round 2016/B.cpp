#include <iostream>
using namespace std;
int dp[101];
int main() {
    freopen("C:\\Users\\Administrator\\Downloads\\B-small-practice.in","r",stdin);
    freopen("C:\\Users\\Administrator\\Downloads\\B-small-attempt0.out","w",stdout);
    int num;
    cin >> num;
    string s;
    for (int i=0; i<num; i++) {
        cin >> s;
        cout << "Case #" << i+1 << ": ";
        if (s[0]=='+')  dp[0] = 0;
        else    dp[0] = 1;
        for (int i =1; i<s.size(); i++) {
            if (s[i] == s[i-1] || ((s[i]=='+')&&(s[i-1]=='-')))    dp[i] = dp[i-1];
            else    dp[i] = dp[i-1] + 2;
        }
        cout << dp[s.size()-1] << endl;
    }
    return 0;
}