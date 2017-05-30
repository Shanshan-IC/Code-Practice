class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num==1) return false;
        int temp = sqrt(num);
        int sum = num-1;
        for (int i = 2; i <= temp; i++) {
            if (num%i==0)  {
                if (i==temp && temp*temp==num)  sum-=i;
                else    sum= sum-i-num/i;
            }
            if (sum<0) return false;
        }
        
        return sum==0;
    }
};