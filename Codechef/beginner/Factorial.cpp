#include <iostream>

using namespace std;

int table[12];
int main() {
    int n;
    long long input;
    cin >> n;
    table[0] = 5;
    for (int i=1; i<12; i++)
        table[i] = table[i-1]*5;
    
    int res = 0;
    while (n--) {
        cin >> input;
        for (int i=0; i<12; i++) {
            if (table[i]>input) break;
            res += input/table[i];
        }
        cout << res << endl;
        res = 0;
    }
    
    return 0;
}