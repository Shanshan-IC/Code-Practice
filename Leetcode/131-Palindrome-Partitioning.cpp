class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        if (s.empty())  return res;
        helper(s, res, 0, curr);
        return res;
    }
    
    void helper(string s, vector<vector<string>> &res, int pos, vector<string> &curr) {
        if (pos==s.size())  res.push_back(curr);
        for (int i=pos; i<s.size(); i++) {
            if (isPalindrome(s, pos, i)) {
                curr.push_back(s.substr(pos, i-pos+1));
                helper(s, res, i+1, curr);
                curr.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int i, int j) {
        while (i<j && s[i]==s[j]) {
            i++;
            j--;
        }
        return i>=j;
    }
};