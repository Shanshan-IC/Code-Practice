#include <iostream>
#include <algorithm>
#include <vector>
int A[10001];

using namespace std;

int main() {
    freopen("/Users/fushanshan/Downloads/A-large.in.txt","r",stdin);
    freopen("/Users/fushanshan/Downloads/A-larget.out","w",stdout);
    int num, N, a;
    cin >> num;
    vector<int> arr;
    for (int i = 0; i < num; i++) {
        cout << "Case #" << i + 1 << ": ";
        cin >> N;
        for (int i = 0;i < N; i++){
            cin >> a;
            arr.push_back(a);
        }
        int mins = 1, maxs = N;
        bool flag = true;
        while (arr.size() > 1 && (arr.size() - 1)/2 >= 0) {
            int p = (arr.size() - 1)/2;
            int pivot = arr[p];
            if (pivot == mins) {
                vector<int>::iterator it = arr.begin()+p;
                arr.erase(it);
                mins++;
                continue;
            } else if (pivot == maxs) {
                vector<int>::iterator it = arr.begin()+p;
                arr.erase(it);
                maxs--;
                continue;
            } else {
                flag = false;
                break;
            }

        }
        arr.clear();
        if (flag) cout << "YES" << endl;
        else cout<<"NO" << endl;
    }
    return 0;
}

