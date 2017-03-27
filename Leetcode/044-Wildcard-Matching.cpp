class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, asterick = -1;
        int match;
        while (i < s.size()) {
            if (j<p.size() && p[j]=='*') {
                match = i;
                asterick = j++;
            }
            else if (j<p.size() && (s[i]==p[j] || p[j]=='?')) {
                i++;
                j++;
            }
            else if (asterick >= 0) {
                i = ++match;
                j = asterick+1;
            }
            else    return false;
        }
        while (j<p.size() && p[j]=='*') j++;
        return j==p.size();
    }
};