#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for (int i=0; i< N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int left = 0, right = N-1;
    while (left<=right) {
        int mid = left+(right-left)/2;
        if (arr[mid] == M) {
            cout << mid+1 << endl;
            break;
        }
        else if (arr[mid] < M)
            left = mid+1;
        else
            right = mid-1;
    }
    if (left>right) cout << -1 << endl;
    return 0;
}