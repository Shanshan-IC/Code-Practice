class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();
        int table[256] =  {0};
        int start = 0, res = 0;
        for (int i=0; i<n; i++) {
            table[s[i]]++;
            while (table[s[i]]>1) {
                table[s[start++]]--;   
            }
            res = max(res, i-start+1);    
        }
        return res;
    }
};