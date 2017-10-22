#include <iostream>
#include <iomanip>

using namespace std;
const int MAXN = 8E3 + 10;
int dp[MAXN][MAXN];

string getNew(string a) {
    string ans = "0";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '*')
            ans += "0000";
        else
            ans += a[i];
    }
    return ans;
}

int main()
{
    freopen("/Users/fushanshan/Downloads/B-large-practice.in","r",stdin);
    freopen("/Users/fushanshan/Downloads/B-large-attempt2.out","w",stdout);
    int num;
    cin >> num;
    string a, b;
    for (int i = 0; i < num; i++) {
        cin >> a >> b;
        cout << "Case #" << i+1 << ": ";
        string m = getNew(a);
        string n = getNew(b);
        const int ms = m.size();
        const int ns = n.size();
        for (int i = 0; i<=ms; i++)
            fill_n(dp[i], ns+1, false);
        dp[0][0] = true;
        for (int i = 0; i <= ms; i++)
            for (int j = 0; j <= ns; j++) {
                if (dp[i][j]) {
                    dp[i][j+1] |= n[j+1]=='0';
                    dp[i+1][j] |= m[i+1] == '0';
                    dp[i+1][j+1] |= m[i+1] == '0' || n[j+1] == '0' || m[i+1] == n[j+1];
                }
            }
        cout << (dp[ms][ns]?"TRUE": "FALSE") << endl;
    }
    return 0;
}

