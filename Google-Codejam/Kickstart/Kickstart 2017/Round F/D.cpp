#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int compute(int n)
{
    int i, k;
    long long i2;
    while ((n & 3) == 0) n >>= 2;
    if ((n & 7) == 7) return 4;
    for (i = 8, i2 = 9; i2 <= n; i2 += i += 8)
        while (n % i2 == 0) n /= i2;
    if (n == 1) return 1;
    if ((n & 1) == 0) n >>= 1;
    if ((n & 3) == 3) return 3;
    for (k = sqrt(n), i = 3; i <= k && n % i; i += 4) ;
    return (i > k) ? 2 : 3;
}

int main()
{
    freopen("/Users/fushanshan/Downloads/D-small-attempt0.in.txt","r",stdin);
    freopen("/Users/fushanshan/Downloads/D-small-attempt0.out","w",stdout);
    int num, N;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cout << "Case #" << i + 1 << ": ";
        cin >> N;
        cout << compute(N) << endl;
    }
}

