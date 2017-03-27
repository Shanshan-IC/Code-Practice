#include <iostream>
using namespace std;

// 思想是100001100001肯定能被100001整除
void help(string s, int base) {
    long long res = 0;
    long long k = 1;
    for (int i=s.size()-1; i>=0; i--) {
        res += (s[i]-'0')*k;
        k *= base;
    }
    cout << res << " ";
}

int main() {
    freopen("C:\\Users\\Administrator\\Downloads\\C-large-practice.in","r",stdin);
    freopen("C:\\Users\\Administrator\\Downloads\\C-large-attempt0.out","w",stdout);
    int num, n, j;
    cin >> num;
    for (int i=0; i<num; i++) {
        cin >> n >> j;
        cout << "Case #" << i + 1 << ":" << endl;
        for (int b = 0; ; b++) {
            string s = "1";
            for (int i=0; i<(n/2)-2; i++) {
                if (b&(1<<i))   s += "1";
                else  s += "0";
            }
            s += "1";
            cout << s << s << " ";
            for (int i=2; i<=10; i++)
                help(s, i);
            cout << endl;
            j--;
            if (j==0)   break;
        }
    }
    return 0;
}