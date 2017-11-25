#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long ll;


int a[10005];

#define REP(i,s,t) for(int i=(s);i<(t);i++)

int main()
{
    freopen("/Users/fushanshan/Downloads/A-large-practice.in","r",stdin);
    freopen("/Users/fushanshan/Downloads/A-large.out","w",stdout);
    int num, N;
    cin >> num;
    long mod = 1000000007;
    long int pow_mod[10005]; //here 'ele' = maximum power upto which you want to store 2^i
    pow_mod[0]=1; //2^0 = 1
    for(int i=1;i<10000;++i){
        pow_mod[i] = (pow_mod[i-1]*2)%mod;
    }
    for (int t = 0; t < num; t++) {
        cout << "Case #" << t+1 << ": ";
        cin >> N;
        REP(i, 0, N) cin >> a[i];
        ll res = 0;
        REP(i, 0, N) {
            REP(j, i+1, N) {
                ll diff = (a[j]-a[i]) % mod;
                ll nums = pow_mod[j-i-1];
                if (diff == 0) continue;
                res = (res + (nums * diff ) % mod) % mod;
            }
        }
        cout << res << endl;
    }
    return 0;
}

