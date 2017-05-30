class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty())   return 0;
        int res = 0, begin=0, last =-1;
        for (int i = 0; i<nums.size();i++) {
            if (nums[i]==0) {
                res = max(res, last-begin+1);
                begin = i+1;
                last = i;
            } else {
                last++;
            }
        }
        return max(res, last-begin+1);
    }
};