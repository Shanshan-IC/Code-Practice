class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (int n: nums)   diff^=n;
        diff &= -diff;
        int num1= 0, num2 = 0;
        for (int n:nums) {
            if ((diff & n)==0)    num1 ^= n;
            else num2^=n;
        }
        return {num1, num2};
    }
};