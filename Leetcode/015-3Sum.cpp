class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        const int n = nums.size();
        if (n<3)    return res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; i++) {
            int j = i+1, k = n-1;
            while (j<k) {
                while (j<k && nums[i]+nums[j]+nums[k] < 0) j++;
                while (j<k && nums[i]+nums[j]+nums[k] > 0) k--;
                if (j<k && nums[i]+nums[j]+nums[k] == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j<k && nums[j]==nums[j+1])   j++;
                    j++;
                    while (j<k && nums[k]==nums[k-1])   k--;
                }
            }
            while (i<n && nums[i]==nums[i+1])   i++;
        }
        return res;
    }
};