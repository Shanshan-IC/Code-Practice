#include <iostream>
using namespace std;
int main() {
    int n, m, temp;
    cin >> n;
    for (int j=1; j<=n; j++) {
        cin >> m >> temp;
        int start=1, end=1, x=1, res=temp, now=temp;
        for (int i=2; i<=m; i++) {
            cin >> temp;
            if (now+temp<temp) {
                now = temp;
                x=i;
            }
            else
                now += temp;
            if (now>res) {
                res = now;
                start=x;
                end = i;
            }
        }
        cout << "Case " << j << ":" << endl << res << " " << start << " " << end << endl;
        if (j!=n)
            cout << endl;
    }
    return 0;
}

