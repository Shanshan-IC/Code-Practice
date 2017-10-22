#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

//# ()()要好过(())这样的了。因为如果只是嵌套的话，配对还只是局限于min对，
//# 而如果相邻放的话，相邻的匹配括号也可以互相组成。然后就是1+2+3+..n了。

int main()
{
    freopen("/Users/fushanshan/Downloads/C-small-practice.in","r",stdin);
    freopen("/Users/fushanshan/Downloads/C-small-attempt2.out","w",stdout);
    int num, l, r;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> l >> r;
        cout << "Case #" << i+1 << ": ";
        int mins = min(l, r);
        cout << (1LL+mins)*mins/2LL << endl;
    }
    return 0;
}

