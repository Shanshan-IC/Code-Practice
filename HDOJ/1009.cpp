#include <iostream>
#include <algorithm>
using namespace std;

struct room {
    double j;
    double f;
    double ratio;
}res[10000];

bool compare(room a, room b) {
    return a.ratio>b.ratio;
}

int main() {
    int m, n;
    while (cin >> m >> n) {
        if (m<0 || n<0) continue;
        double ans = 0;
        for (int i=0; i<n; i++) {
            cin >> res[i].j >> res[i].f;
            res[i].ratio = res[i].j/res[i].f;
        }
        sort(res, res+n, compare);
        for (int i=0; i<n; i++) {
            if (m>res[i].f) {
                m -= res[i].f;
                ans += res[i].j;
            }
            else {
                ans += m*res[i].ratio;
                break;
            }
        }
        printf("%.3f\n", ans);
    }
    return 0;
}