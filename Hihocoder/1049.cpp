#include <iostream>
#include <string>
using namespace std;

string pre, mid;
int point;  // for preorder traversal
//curr is the root, recusive between a and b
void DFS(int a, int curr, int b) {
    if (a==b) {
        cout << mid[curr];
        return;
    }
    if (curr-a!=0)
        DFS(a, mid.find(pre[++point]), curr-1);
    if (curr-b!=0)
        DFS(curr+1, mid.find(pre[++point]), b);
    cout << mid[curr];
}

int main() {
    cin >> pre >> mid;
    DFS(0, mid.find(pre[0]), pre.size()-1);
    return 0;
}