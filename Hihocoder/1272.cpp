#include <iostream>

using namespace std;

int cost[50];
int sat[50];

int getMax(int n) {
    int res = 0;
    for (int i=0; i<n; i++)
        if (cost[i] % 50 == 0)
            res = max(res, sat[i]);
    
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if ((cost[i]+cost[j])%50==0)
                res = max(res, sat[i]+sat[j]);
    
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            for (int k=j+1; k<n; k++)
                if ((cost[i]+cost[j]+cost[k])%50==0)
                    res = max(res, sat[i]+sat[j]+sat[k]);
    return res;
}


int main() {
    int n, m;
    cin >> n;
    double temp;
    while (n--) {
        cin >> m;
        for (int i=0; i<m; i++) {
            scanf("%lf %d", &temp, &sat[i]);
            cost[i] = 10*temp;
        }
        cout << getMax(m) << endl;
    }
    
    return 0;
}