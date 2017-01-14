#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> vec(N);
    for (int i=0; i<N; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    cout << vec[K-1] << endl;
    return 0;
}