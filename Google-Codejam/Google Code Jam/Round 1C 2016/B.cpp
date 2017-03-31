#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("C:\\Users\\Administrator\\Downloads\\B-small-practice.in","r",stdin);
    freopen("C:\\Users\\Administrator\\Downloads\\B-small-attempt0.out","w",stdout);
    int num, B;
    long long M;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cout << "Case #" << i + 1 << ": ";
        cin >> B >> M;
        if (M > (1LL << (B - 2)))   cout << "IMPOSSIBLE" << endl;
        else {
            cout << "POSSIBLE" << endl;
            for (int i = 0; i< B; i++) {
                for (int j = 0; j < B; j++) {
                    if (i < j && j < B - 1)     cout << "1";
                    else if (j == B - 1 && (i == 0 || (M - 1) & 1LL<<(i - 1)))   cout << "1";
                    else    cout << "0";
                }
                cout << endl;
            }
        }
    }
    return 0;
}