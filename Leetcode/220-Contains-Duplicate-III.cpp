class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty())   return false;
        map<int, int> m;
        int j = 0;
        for (int i=0; i<nums.size(); i++) {
            if (i-j >k && m[nums[j]]==j)
                m.erase(nums[j++]);
            auto a = m.lower_bound(nums[i]-t);
            if (a!=m.end() && abs(a->first - nums[i])<=t)
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};