class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        int res[n] = {0};
        res[0] = nums[0];   
        int maxs = nums[0];
        for (int i=1; i<n; i++) 
            res[i] = max(nums[i], res[i-1]+nums[i]);
        for (int i=1; i<n; i++) 
            maxs = max(maxs, res[i]);
        return maxs;
    }
};