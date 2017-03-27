#include <iostream>
#include <cmath>
using namespace std;

bool isvalid(long long num, long long j) {
    while (num) {
        if (num % j != 1)   return false;
        num /= j;
    }
    return true;
}
int main() {
    freopen("//Users//fushanshan//Downloads//B-large-practice.in","r",stdin);
    freopen("//Users//fushanshan//Downloads//B-large-attempt0.out","w",stdout);
    int N;
    cin >> N;
    long long num;
    for (int i=0; i<N; i++) {
        cin >> num;
        // long long half = sqrt(num);
        for (long long j=2; j<=num; j++) {
            if (isvalid(num, j)) {
                cout << "Case #" << i+1 << ": " << j << endl;
                break;
            }
        }
    }
    return 0;
}