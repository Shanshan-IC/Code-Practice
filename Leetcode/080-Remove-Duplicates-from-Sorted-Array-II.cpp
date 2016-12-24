class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1;
        const int n = nums.size();
        if (n<2)    return n;
        for (int i=1; i<n; i++) {
            if (i+1<n && nums[i-1]==nums[i] && nums[i]==nums[i+1])
                continue;
            nums[index++] = nums[i];
        }
        return index;
    }
};