class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.empty())   return res;
        int left = 0, right = nums.size()-1;
        while (left<=right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) {
                int i = mid, j = mid;
                while (i-1>=0 && nums[i-1]== nums[i])   i--;
                while (j+1<nums.size() && nums[j+1]== nums[j])   j++;
                return {i, j};
            }
            else if (nums[mid] < target)
                left = mid+1;
            else    right = mid-1;
        }
        return {-1, -1};
    }
};