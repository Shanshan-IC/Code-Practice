class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        const int n = nums.size();
        if (n<4)    return res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int k = j+1;
                int m = n-1;
                while (k<m) {
                while (k<m && nums[i]+nums[j]+nums[k]+nums[m] < target) k++;
                while (k<m && nums[i]+nums[j]+nums[k]+nums[m] > target) m--;
                if (k<m && nums[i]+nums[j]+nums[k]+nums[m] == target) {
                    res.push_back({nums[i], nums[j], nums[k], nums[m]});
                    while (k<m && nums[k]==nums[k+1])   k++;
                    k++;
                    while (k<m && nums[m]==nums[m-1])   m--;
                }
                }
                while (j<n && nums[j]==nums[j+1])   j++;
            }
            while (i<n && nums[i]==nums[i+1])   i++;
        }
        return res;
    }
};