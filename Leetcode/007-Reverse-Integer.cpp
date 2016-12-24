class Solution {
public:
    int reverse(int x) {
        bool neg =false;
        long y = x;
        if (y<0)
        {
             y = -y;
             neg = true;
        }
        long res = 0;
        while (y)
        {
            res = res *10+y%10;
            y /= 10;
        }
        if (!neg && res > INT_MAX || neg && -res < INT_MIN)
            return 0;
        return (neg)?-res:res;
    }
};