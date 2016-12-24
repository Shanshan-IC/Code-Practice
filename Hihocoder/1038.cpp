#include <iostream>

using namespace std;

int maxValue(int need[], int value[], int n, int m) {
    int* f = new int[m+1];
    for (int i=0; i<n; i++) {
        for (int j=m;j>=need[i]; j--)
            f[j] = max(f[j], f[j-need[i]]+value[i]);
    }
    return f[m];
}

int main() {
    int n, m;
    cin >> n >> m;
    int need[n], value[n];
    for (int i=0; i<n; i++)
        cin >> need[i] >> value[i];
    cout << maxValue(need, value, n, m) << endl;
    return 0;
}