class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> res;
        helper(curr, res, s, 0);
        return res;
    }
    
    void helper(vector<string> &curr, vector<vector<string>> &res, string s, int pos) {
        if (pos == s.size())    res.push_back(curr);
        for (int i=pos; i<s.size(); i++) {
            if (isPalindrome(s, pos, i)) {
                curr.push_back(s.substr(pos, i-pos+1));
                helper(curr, res, s, i+1);
                curr.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int i, int j){
        while (i<j && s[i]==s[j]){
            i++;
            j--;
        }
        return i>=j;
    }
};