class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        if (n<2)    return s;
        int i = 1;
        int res = 0, begin = 0;
        for (int i=0; i<n; i++) {
            int j = i;
            while (j<n && s[j]==s[j+1]) j++;
            int left = i, right = j;
            while (left>=0 && right<n && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right-left-1 > res) {
                res = right - left -1;
                begin = left+1;
            }
        }
        return s.substr(begin, res);
    }
};