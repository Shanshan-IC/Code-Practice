#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
typedef unordered_map<int,int> mymap;
// 思路很简单，出现个数为奇数的则是遗漏的
int main() {
    freopen("C:\\Users\\Administrator\\Downloads\\B-small-practice.in","r",stdin);
    freopen("C:\\Users\\Administrator\\Downloads\\B-small-attempt0.out","w",stdout);
    int num, n, a;
    cin >> num;
    mymap m;
    vector<int> vec;
    for (int i=0; i<num; i++) {
        m.clear();
        vec.clear();
        cout << "Case #" << i+1 << ": ";
        cin >> n;
        int k = n * (2 * n - 1);
        while (k--) {
            cin >> a;
            m[a]++;
        }
        for (mymap::iterator iter = m.begin(); iter != m.end(); iter++)
            if (iter->second % 2 !=0)
                vec.push_back(iter->first);
        sort(vec.begin(), vec.end());
        for (int i=0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
    }
    return 0;
}