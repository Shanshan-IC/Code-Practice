class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        if (s.empty())  return 0;
        const int n = s.size();
        for (int i=0; i<n; i++) {
            if (s[i] != ' ')    len++;
            else {
                while (i<n && s[i]==' ')   i++;
                if (i<n && s[i]!=' ')   len = 1;
            }
        }
        return len;
    }
};