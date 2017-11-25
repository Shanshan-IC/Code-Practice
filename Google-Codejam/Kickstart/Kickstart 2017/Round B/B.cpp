#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
double x[10007], y[10007], w[10007];
int N;
double cal_score(double X, double Y, int N) {
    double ans  = 0.0;
    REP(i, 0, N)    {
        ans += max(abs(X-x[i]), abs(Y-y[i]))*w[i];
    }
    return ans;
}

double calc(double x, int N) {
    double l = -10000, r = 10000;
    int T = 100;
    while (T--) {
        double m1 = (l*2+r) / 3;
        double m2 = (l+2*r) / 3;
        double f1 = cal_score(x, m1, N);
        double f2 = cal_score(x, m2, N);
        if (f1 < f2)    r = m2;
        else l = m1;
    }
    return cal_score(x, l, N);
}

double calc(int N) {
    double l = -10000, r = 10000;
    int T = 100;
    while (T--) {
        double m1 = (l*2+r) / 3;
        double m2 = (l+2*r) / 3;
        double f1 = calc(m1, N);
        double f2 = calc(m2, N);
        if (f1 < f2)    r = m2;
        else l = m1;
    }
    return calc(l, N);
}

int main()
{
    freopen("/Users/fushanshan/Downloads/B-large-practice.in","r",stdin);
    freopen("/Users/fushanshan/Downloads/B-large.out","w",stdout);
    int num, N;
    cin >> num;
    for (int t = 0; t < num; t++) {
        cin >> N;
        REP(i, 0, N) cin >> x[i] >> y[i] >> w[i];
        printf("Case #%d: %.12lf\n", t+1, calc(N));
    }
    return 0;
}

