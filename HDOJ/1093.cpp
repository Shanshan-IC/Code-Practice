#include <iostream>

using namespace std;

int main() {
    int n, m, a;
    cin >> n;
    while (n--) {
        cin >> m;
        int res = 0;
        while (m--) {
            cin >> a;
            res += a;
        }
        cout << res << endl;
    }
    return 0;
}