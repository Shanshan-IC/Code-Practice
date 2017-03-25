class Solution {
public:
    int minCut(string s) {
        const int n = s.size();
        vector<vector<int>> isPal(n, vector<int>(n, 0));
        int cut[n] = {0};
        for (int j=0; j<n; j++){
            cut[j] = j;
            for (int i=0; i<=j; i++) {
                if (s[i] == s[j] &&(j-i<=1 || isPal[i+1][j-1])) {
                    isPal[i][j] = 1;
                    if (i>0)    cut[j] = min(cut[j], cut[i-1]+1);
                    else    cut[j] = 0;
                }
            }
        }
        return cut[n-1];
    }
};