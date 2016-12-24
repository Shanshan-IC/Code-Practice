#include <iostream>

using namespace std;

int main() {
    int n, a;
    while (cin >> n) {
    	if (n==0)	break;
        int res = 0;
        while (n--) {
        	cin >> a;
        	res += a;
        }
        cout << res << endl;
    }
    return 0;
}