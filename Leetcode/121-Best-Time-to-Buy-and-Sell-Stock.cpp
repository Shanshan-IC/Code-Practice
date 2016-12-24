class Solution {
public:
    int maxProfit(vector<int>& nums) {
        if (nums.empty())   return 0;
        int res = 0, minP = INT_MAX;
        for (int p:nums) {
            minP = min(p, minP);
            res = max(res, p-minP);
        }
        return res;
    }
};