#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int m, N, P, W, H;
    int a[1005];
    cin >> m;
    while (m--) {
        cin >> N >> P >> W >> H;
        for (int i=0; i<N; i++)
            cin >> a[i];
        int max = W>H?H:W;
        for (int i=max; ;i--) {
            int lines = 0;
            int perline = W/i;
            for (int j=0; j<N; j++)
                lines += ceil(a[j]/(double)perline);
            if (ceil(lines/(H/i)) <=P) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
