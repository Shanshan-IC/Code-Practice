#include <iostream>

using namespace std;

int main() {
    int count = 0;
    int n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        if (a%2 ==0)
            count++;
        else
            count--;
    }
    cout << (count>0?count:-count) << endl;
    return 0;
}