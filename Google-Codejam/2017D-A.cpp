#include <iostream>
using namespace std;

/* 扩展卡特兰数
n个1，m个0，n > m 要保证任意一个位置1的个数都大于0的个数。 
保证第一个数为1，后面n - 1个1和m个0符合扩展卡特兰数即可 
n - 1个1，m个0构成的卡特兰数的最终解为ans = C(n + m - 1, n - 1) - C(n + m - 1,n) 
*/
int main() {
    freopen("//Users//fushanshan//Downloads//A-large-practice.in","r",stdin);
    freopen("//Users//fushanshan//Downloads//A-large-attempt0.out","w",stdout);
    int num;
    cin >> num;
    int M, N;
    for (int i=0; i<num; i++) {
        cin >> N >> M;
        double ans = (N-M) * 1.0 / (N+M);
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
    return 0;
}