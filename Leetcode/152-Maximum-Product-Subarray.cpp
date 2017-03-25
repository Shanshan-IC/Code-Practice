class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = 1, minP = 1, res = INT_MIN;
        for (int num: nums) {
            int temp = maxP;
            maxP = max(max(maxP*num, minP*num), num);
            minP = min(min(minP*num, temp*num), num);
            res = max(res, maxP);
        }
        return res;
    }
};