#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int i, int j) {
    return i>j;
}

bool isValid(vector<int> vec) {
    if (vec[0] >2)  return false;
    if (vec[0] == 2 && vec[1]>3)    return false;
    if (vec[2] > 5) return false;
    return true;
}
int main() {
    vector<int> input(4);
    for (int i=0; i<4; i++)
        cin >> input[i];
    bool flag = false;
    sort(input.begin(), input.end(), compare);
    do {
        if (isValid(input)) {
            flag = true;
            cout << input[0] << input[1] << ":" << input[2] << input[3] << endl;
            break;
        }
        
    } while (prev_permutation(input.begin(), input.end()));
    if (!flag)  cout << "NOT POSSIBLE" << endl;
    return 0;
}