class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0]+nums[1]+nums[2];
        int diff = abs(target - ans);
        if (diff==0)    return ans;
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; i++) {
            int j = i+1;
            int k = n-1;
            while (j<k) {
                int temp = nums[i]+nums[j]+nums[k];
                int newDiff = abs(target-temp);
                if (newDiff<diff) {
                    ans = temp;
                    diff = newDiff;
                }
                if (temp<target)    j++;
                else    k--;
            }
        }
        return ans;
    }
};