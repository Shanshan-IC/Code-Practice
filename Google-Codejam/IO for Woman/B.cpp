#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    freopen("C:\\Users\\fushanshan\\Downloads\\B-large-practice.in","r",stdin);
    freopen("C:\\Users\\fushanshan\\Downloads\\B-large-attempt0.out","w",stdout);
    int num, N;
    double a;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cout << "Case #" << i + 1 << ": ";
        cin >> N;
        vector<double> v;
        for (int j = 0; j < 2*N; j++) {
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        double res = 1;
        for (int j = 0; j < N; j++) {
            res *= (1 - v.at(j) * v.at(2 * N-j-1));
        }

        cout << res << endl;
        v.clear();
    }
    return 0;
}