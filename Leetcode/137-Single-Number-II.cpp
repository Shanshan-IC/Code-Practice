class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for (int n: nums) {
            two |= (n&one);
            one ^= n;
            int t = one & two;
            one &= (~t);
            two &= (~t);
        }
        return one;
    }
};