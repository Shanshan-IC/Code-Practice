class Solution {
public:
    bool isPowerOfThree(int n) {
        double temp = log10(n)/log10(3);
        return temp==int(temp);
    }
};
