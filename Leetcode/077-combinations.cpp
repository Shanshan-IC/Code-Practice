class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        if (n<k)    return res;
        helper(res, curr, 1, n, k);
        return res;
    }
    
    void helper(vector<vector<int>> &res, vector<int> &curr, int pos, int n, int k) {
        if (k==0){
            res.push_back(curr);
            return;
        }
        for (int i=pos; i<=n; i++) {
            curr.push_back(i);
            helper(res, curr, i+1, n, k-1);
            curr.pop_back();
        }
    }
};