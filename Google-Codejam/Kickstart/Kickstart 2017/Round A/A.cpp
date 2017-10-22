
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long l;
// sum(r-s)*(c-s)*s
const ll MOD = 1E9 + 7, INV2 = (MOD + 1) / 2, INV3 = (MOD + 1) / 3;


int main()
{
    freopen("/Users/fushanshan/Downloads/A-large-practice.in","r",stdin);
    freopen("/Users/fushanshan/Downloads/A-large-attempt2.out","w",stdout);
    ll num, n, m;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> n >> m;
        cout << "Case #" << i+1 << ": ";
        ll mins = min(m, n);
        l c1 = mins * (mins + 1) / 2 % MOD;
        ll c2 = c1 * (2 * mins + 1) % MOD * INV3 % MOD;
        ll c3 = c1 * c1 % MOD;
        ll ans = n * m % MOD * c1 % MOD;
        ans = (ans - (n + m) * c2) % MOD;
        ans = (ans + c3) % MOD;
        cout << (ans+MOD)%MOD << endl;
    }
    return 0;
}

