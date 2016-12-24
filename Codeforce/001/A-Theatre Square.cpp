#include <iostream>
using namespace std;

int main() {
    int n, m, a;
    cin >> n >> m >> a;
    int c = n/a + ((n%a==0)?0:1);
    int d = m/a + ((m%a==0)?0:1);
    cout << c*d << endl;
    
    return 0;
}