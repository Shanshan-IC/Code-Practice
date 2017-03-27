#include <iostream>
using namespace std;

int main() {
    freopen("C:\\Users\\Administrator\\Downloads\\A-large-practice.in","r",stdin);
    freopen("C:\\Users\\Administrator\\Downloads\\A-large-attempt0.out","w",stdout);
    int num, m;
    cin >> num;
    for (int i=0; i<num; i++) {
        cin >> m;
        cout << "Case #" << i+1 << ": ";
        if ( m==0 ) cout << "INSOMNIA" << endl;
        else {
            int n = 0;
            int x;
            for (x = m; n < (1 << 10) - 1; x += m) {
                int y = x;
                while (y) {
                    n |= 1 << (y % 10);
                    y /= 10;
                }
            }
            cout << x-m << endl;
        }
    }
    return 0;
}