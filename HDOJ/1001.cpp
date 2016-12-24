#include <iostream>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        if (n%2==0)
            cout << n/2*(1+n) << endl << endl;
        else
            cout << (n+1)/2*n << endl << endl;
    }
    return 0;
}

