#include <iostream>
using namespace std;
int main() {
    cout << "n e" << endl << "- -----------" << endl << 0 <<" " << 1 << endl << 1 <<" " << 2 << endl << 2 << " " << 2.5 << endl;
    double e = 2.5;
    int temp = 2;
    for (int i=3; i<=9; i++) {
        temp *= i;
        e += 1.0/double(temp);
        printf("%d %.9lf\n", i, e);
    }
    return 0;
}

