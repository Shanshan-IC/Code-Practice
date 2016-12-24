class Solution {
public:
    int maxArea(vector<int>& nums) {
        if (nums.empty())   return 0;
        int left = 0, right = nums.size()-1;
        int res = 0;
        while (left<right) {
            int temp = (right-left)*min(nums[left], nums[right]);
            res = max(res, temp);
            if (nums[left]<nums[right]) left++;
            else    right--;
        }
        return res;
    }
};