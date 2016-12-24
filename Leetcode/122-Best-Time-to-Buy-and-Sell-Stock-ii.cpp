class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int res = 0, minP = INT_MAX;
        if (nums.empty())   return 0;
        for (int p:nums) {
            if (p>minP) res+=p-minP;
            minP = p;
        }
        return res;
    }
};