#include <iostream>
#include <unordered_map>

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

using namespace std;


int main() {
    freopen("C:\\Users\\fushanshan\\Downloads\\A-large-practice.in","r",stdin);
    freopen("C:\\Users\\fushanshan\\Downloads\\A-large-attempt0.out","w",stdout);
    int num, F, S, a, b;
    unordered_map<int, int> res;
    unordered_map<pair<int, int>, int, pair_hash> temp;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cout << "Case #" << i + 1 << ": ";
        cin >> F >> S;
        for (int j = 0; j < F; j++) {
            cin >> a >> b;
            if (a == b)     res[a] += 1;
            else {
                pair<int, int> temp_P = (a > b) ? make_pair(a, b) : make_pair(b, a);
                if (temp[temp_P] == 0) {
                    res[a] += 1;
                    res[b] += 1;
                    temp[temp_P] += 1;
                }
            }

        }
        int ans = 0;
        for( int j = 1; j <= S; j++){
            if (ans < res[j])
                ans = res[j];
        }
        cout << ans << endl;
        res.clear();temp.clear();
    }
    return 0;
}