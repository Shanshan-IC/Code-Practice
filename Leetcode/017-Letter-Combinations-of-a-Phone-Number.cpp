class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        vector<string> table = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs","tuv","wxyz"};
        helper(digits, table, 0, "", res);
        return res;
    }
    
    void helper(string digits, vector<string> table, int pos, string curr, vector<string> &res) {
        if (pos == digits.size()) {
            res.push_back(curr);
            return;
        }
        
        for (int i=0; i<table[digits[pos]-'0'].size(); i++) {
            helper(digits, table, pos+1, curr+table[digits[pos]-'0'][i], res);
        }
    }
};