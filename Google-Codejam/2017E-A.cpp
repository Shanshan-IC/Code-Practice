#include <iostream>
#include <fstream>
#define LL long long 
using namespace std;

void countF(string pattern, LL left, LL right) {
    int len = pattern.size();
    LL l1 = left / len, l2 = left % len;
    LL r1 = right / len, r2 = right % len;
    LL count = 0, ll = 0, rr = 0;
    for (int i=0; i<len; i++) {
        if (pattern[i] == 'B')  count++;
        if (i+1 == l2)  ll = count;
        if (i+1 == r2)  rr = count;
    }
    LL sum1 = r1*count+rr;
    LL sum2 = l1*count+ll;
    cout << sum1 - sum2 << endl;
}

int main() {
    int N;
    LL left, right;
    freopen("//Users//fushanshan//Downloads//A-large-practice.in","r",stdin);
    freopen("//Users//fushanshan//Downloads//A-large-attempt0.out","w",stdout);
    cin >> N;
    string pattern;
    for (int i=0; i<N; i++) {
        cin >> pattern;
        cin >> left >> right;
        printf("Case #%d: ",i+1);
        countF(pattern, left-1, right);

    }
    return 0;
}