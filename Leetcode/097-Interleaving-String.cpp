class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int n = s1.size();
        const int m = s2.size();
        const int p = s3.size();
        if (n+m != p)   return false;
        vector<vector<bool>> res(n+1, vector<bool>(m+1, false));
        for (int i=0; i<n+1; i++)
            for (int j=0; j<m+1; j++) {
                if (i==0 && j==0)   res[i][j]=true;
                else if (i==0)   res[i][j] = res[i][j-1] & (s2[j-1]==s3[j-1]);
                else if (j==0)  res[i][j] = res[i-1][j] & (s1[i-1]==s3[i-1]);
                else    res[i][j] = (res[i-1][j] & (s1[i-1]==s3[i+j-1])) || (res[i][j-1] & (s2[j-1]==s3[i+j-1]));
            } 
        return res[n][m];
    }
};