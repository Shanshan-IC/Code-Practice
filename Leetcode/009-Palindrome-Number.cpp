class Solution {
public:
    bool isPalindrome(int x) {
        int val = 0;
        int k = x;
        if (x<0)    return false;
        while (k) {
            int temp = k%10;
            val = val*10 + temp;
            k /= 10;
        }
        return val == x;
    }
};