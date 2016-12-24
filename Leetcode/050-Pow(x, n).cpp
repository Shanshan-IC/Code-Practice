class Solution {
public:
    double myPow(double x, int n) {
        if (n==0)   return 1;
        if (x==0)   return 0;
        if (n>0)    return helper(x, n);
        else    return helper(1/x, -n);
    }
    
    double helper(double x, int n) {
        if (n==0)   return 1;
        double half = helper(x, n/2);
        if (n%2==0)
            return half*half;
        else
            return half*half*x;
    }
};