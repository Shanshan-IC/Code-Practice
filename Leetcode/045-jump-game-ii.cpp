class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, last = 0, curr = 0;
        for (int i=0; i<nums.size(); i++) {
            if (i>last) {
                last = curr;
                ++res;
            }
            curr = max(curr, i+nums[i]);
        }
        return res;
    }
};