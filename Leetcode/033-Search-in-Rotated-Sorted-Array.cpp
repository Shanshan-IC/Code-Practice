class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())   return -1;
        int left=0, right = nums.size();
        while (left < right) {
            int mid = left+(right-left)/2;
            if (nums[mid]==target)  return mid;
            if (nums[mid] > nums[left]) {
                if (nums[left]<=target && target<nums[mid])
                    right = mid;
                else
                    left = mid+1;
            }
            else {
                if (nums[mid]<target && target<=nums[right-1])
                    left = mid+1;
                else
                    right = mid;
            }
        }
        return -1;
    }
};