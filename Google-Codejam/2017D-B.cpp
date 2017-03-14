#include <iostream>
#include <algorithm>
using namespace std;

/*
for one row, the maximum numbers are m - m/3
for three rows, the maximum numbers are 2*m
for n (n>3) rows, the first row has to be k = m-m/3
n/3 use 2*m the ways to fill in
n%3
if there still is one row, fill in m-m/3
if there still are two rows, the rules are:
consider the relationship between m%3 and the numbers of every row
1. the first row has to be k = m-m/3
2. when m%3==0, three rows numbers must be k, k, k
   when m%3==1, three rows numbers must be k, k, k-1
   when m%3==2, three rows numbers must be k, k-1, k-1
so if m%3!= 2, the two rows both must be filled in k and k, otherwise it should be k and k-1
*/
int main() {
    freopen("//Users//fushanshan//Downloads//B-small-practice.in","r",stdin);
    freopen("//Users//fushanshan//Downloads//B-small-attempt0.out","w",stdout);
    int num;
    cin >> num;
    int m, n;
    for (int i=0; i<num; i++) {
        cin >> n >> m;
        int res=0;
        if (n>m)    swap(n, m);
        int k = m - m/3;    // the maximum numbers in one row
        res += n/3 * 2 * m;
        int temp = n%3;
        if (temp==1)    res += k;
        else if (temp==2) {
            if (m%3==2 && n>3) res = res+(k+k-1);
            else    res = res+2*k;
        }
        cout << "Case #" << i+1 << ": " << res << endl;
    }
    return 0;
}