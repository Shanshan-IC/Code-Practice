#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("C:\\Users\\Administrator\\Downloads\\A-large-practice.in","r",stdin);
    freopen("C:\\Users\\Administrator\\Downloads\\A-large-attempt0.out","w",stdout);
    int num, N;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cout << "Case #" << i + 1 << ": ";
        cin >> N;
        int a[26];
        for (int i = 0; i < N; i++)     cin >> a[i];
        while (1) {
            vector<int> all;
            int maxh = *max_element(a, a+N);
            if (maxh == 0)  break;
            for (int i = 0; i < N; i++)
                if (a[i] == maxh)
                    all.push_back(i);
            if (all.size() == 2)  {
                printf("%c%c ", 'A' + all[0], 'A' + all[1]);
                a[all[0]]--;
                a[all[1]]--;
            }
            else  {
                printf("%c ", 'A' + all[0]);
                a[all[0]]--;
            }
        }
        cout << endl;
    }
    return 0;
}