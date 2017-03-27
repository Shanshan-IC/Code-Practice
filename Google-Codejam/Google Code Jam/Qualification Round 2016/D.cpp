#include <iostream>
using namespace std;

int main() {
    freopen("C:\\Users\\Administrator\\Downloads\\D-small-practice.in","r",stdin);
    freopen("C:\\Users\\Administrator\\Downloads\\D-small-attempt0.out","w",stdout);
    int num, n, j;
    cin >> num;
    for (int i=0; i<num; i++) {
        cout << "Case #" << i+1 << ":";
        long long k, c, s;
        cin >> k >> c >> s;
        if (c * s < k)
            cout << " IMPOSSIBLE\n";
        else {
            long long x = 0;
            for(int i=0; i< k; i++) {
                x = x * k + i;
                if (i + 1 == k || i % c == c - 1) {
                    cout << ' ' << x + 1;
                    x = 0;
                }
            }
            cout << '\n';
        }
    }
    return 0;
}