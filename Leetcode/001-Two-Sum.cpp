class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        const int n = nums.size();
        unordered_map<int, int> m;
        for (int i=0; i<n; i++)
            m[nums[i]] = i;
        for (int i=0; i<n; i++) {
            if (m[target-nums[i]]) {
                res.push_back(i);
                res.push_back(m[target-nums[i]]);
                break;
            }
        }
        return res;
    }
};