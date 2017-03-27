#include <iostream>
using namespace std;

long long getPartioning(int num, int d) {
    long long res = 0;
    int i,k,m,l,r;
    for (i=d; i<num; i+=d)
        for (k=(num-1-i)/(i+2)+2; k<=num/i; k++) {
            m = num-k*i;
            l = m-k+1;  if (l<0)   l=0;
            r = m/2;    if (r>k-1)  r=k-1;
            if (l<=r)   res+=(r-l+1);
        }
    if (num%d ==0)  res++;
    return res;    
}
int main() {
    freopen("//Users//fushanshan//Downloads//C-small-practice.in","r",stdin);
    freopen("//Users//fushanshan//Downloads//C-small-attempt0.out","w",stdout);
    int N;
    cin >> N;
    int num, d;
    for (int i=0; i<N; i++) {
        cin >> num >> d;
        cout << "Case #" << i+1 << ": " << getPartioning(num, d) << endl;
    }
    return 0;
}