class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        helper(res, curr, candidates, target, 0);
        return res;
    }
    
    void helper(vector<vector<int>> &res, vector<int>& curr, vector<int>& candidates, int target, int pos) {
        if (target==0) {
            res.push_back(curr);
            return;
        }
        for (int i=pos; i<candidates.size() && target>0; i++) {
            curr.push_back(candidates[i]);
            helper(res, curr, candidates, target-candidates[i], i+1);
            curr.pop_back();
            while (i<candidates.size() && candidates[i]==candidates[i+1])   i++;
        }
    }
};