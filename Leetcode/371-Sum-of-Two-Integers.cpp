class Solution {
public:
    int getSum(int a, int b) {
        int res = a^b;
        int carray = (a&b)<<1;
        if (carray!=0)  return getSum(res, carray);
        return res;
    }
};