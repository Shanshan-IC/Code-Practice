#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

int table[11] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};


int main() {
    string input;
    cin >> input;
    
    const int n = input.size();
    set<string> res;
    unordered_map<char, int> map;
    
    string curr;
    for (int i=0; i<n; i++) {
        for (int j=1; j+i<= n; j++) {
            curr = input.substr(i, j);
            int count = 0;
            for (int k=0; k<curr.size(); k++) {
                if (map[curr[k]]==0) {
                    count++;
                    map[curr[k]] =1;
                }
            }
            for (int m=0; m<11; m++) {
                if (count == table[m]) {
                    res.insert(curr);
                    break;
                }
                else if (count <table[m])
                    break;
            }
            map.clear();
        }
    }
    
    set<string>::iterator it = res.begin();
    while (it!=res.end()) {
        cout << *it << endl;
        it++;
    }
    return 0;
}