#include <iostream>

using namespace std;

int main() {
    int n, k, input;
    cin >> n >> k;
    int count = 0;
    while (n--) {
        cin >> input;
        if (input %k ==0)
            count++;
    }
    cout << count << endl;
    return 0;
}