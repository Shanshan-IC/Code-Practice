#include <iostream>
#include <algorithm>
#include <vector>
int A[10001];

using namespace std;

int main() {
    freopen("/Users/fushanshan/Downloads/B-small-attempt0.in.txt","r",stdin);
    freopen("/Users/fushanshan/Downloads/B-small-attempt0.out","w",stdout);
    int num, E, N, a;
    cin >> num;
    vector<int> arr;
    for (int j = 0; j < num; j++) {
        cout << "Case #" << j + 1 << ": ";
        cin >> E >> N;
        long energy = E, coins = 0, left = 0, right = N-1;
        for (int i = 0;i < N; i++){
            cin >> a;
            arr.push_back(a);
        }
        sort(arr.begin(), arr.end());
        while (left <= right) {
            if (energy > arr[left]) {
                //Dance
                coins++;
                energy -= arr[left];
                left++;
            } else if (coins > 0 && arr[right] > arr[left]) {
                coins--;
                energy += arr[right];
                right--;
            } else
                break;
        }
        cout << coins << endl;
        arr.clear();
    }
    return 0;
}

