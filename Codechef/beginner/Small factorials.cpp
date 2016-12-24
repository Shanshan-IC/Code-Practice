#include <iostream>

using namespace std;

int main() {
    long long table[100];
    table[0] = 1;
    for (int i=1; i<100; i++)
        table[i] = table[i-1] * (i+1);
    
    int n, input;
    cin >> n;
    while (n--) {
        cin >> input;
        cout << table[input-1] << endl;
    }
    return 0;
}