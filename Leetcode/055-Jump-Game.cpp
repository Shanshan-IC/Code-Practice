class Solution {
public:
    bool canJump(vector<int>& nums) {
        int temp = 1;
        for (int n:nums) {
            if (temp==0)    return false;
            temp = max(temp-1, n);
        }
        return true;
    }
};