#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    freopen("E:/B-small-practice.in","r",stdin);
    freopen("E:/B-small-practice.out","w",stdout);
    int T, N, M;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << "Case #" << i + 1 << ": ";
        cin >> N >> M;
        cout << (N-M)*1.0/(N+M) << endl;
    }
    return 0;
}