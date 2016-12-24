#include <iostream>

using namespace std;

int main() {
    int m, a;
    while (cin >> m) {
        int res = 0;
        while (m--) {
            cin >> a;
            res += a;
        }
        cout << res << endl;
    }
    return 0;
}