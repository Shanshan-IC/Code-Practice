#include <iostream>
#include <string>

using namespace std;

int data[105];

int main() {
    int T;
    scanf("%d", &T);
    
    int n, m;
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i=1; i<=n; i++)
            scanf("%d", &data[i]);
        if (m>=n)   cout << 100 << endl;
        else {
            int res = 0;
            for (int i=m+1; i<=n; i++) {
                if (data[i] - data[i-m-1] - 1 > res)
                    res = data[i] - data[i-m-1] - 1;
            }
            cout << res << endl;
        }
    }
    return 0;
}