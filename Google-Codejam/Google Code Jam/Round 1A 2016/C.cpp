#include <iostream>
#define MAXN 1005
using namespace std;
int a[MAXN];

int main() {
    freopen("C:\\Users\\Administrator\\Downloads\\C-small-practice.in","r",stdin);
    freopen("C:\\Users\\Administrator\\Downloads\\C-small-attempt0.out","w",stdout);
    int num, N;
    cin >> num;
    string s1, s2;
    for (int i = 0; i < num; i++) {
        cout << "Case #" << i + 1 << ": ";
        cin >> N;
        for (int i = 1; i<= N; i++)     cin >> a[i];
        int cnt[MAXN] = {0}, d[MAXN] = {0};
        int ans = 0, res = 0;
        for (int i = 1; i<= N; i++) {
            bool map[N] = {false};
            int x = i;
            map[x] = true;
            while (1) {
                x = a[x];
                if (map[x])  break;
                map[x] = true;
                ++cnt[i];
            }
            if (x==i)   ans = max(ans, cnt[i]+1);
        }
        for (int j = 1; j <= N; j++)
            for (int i = 1; i <= N; i++)
                if (a[a[i]] != i)
                    d[a[i]] = max(d[a[i]], d[i] + 1);

        for (int i = 1; i <= N; i++)
            if (a[a[i]] == i)
                res += d[i] + d[a[i]] + 2;
        res >>= 1;
        cout << max(ans, res) << endl;
    }
    return 0;
}