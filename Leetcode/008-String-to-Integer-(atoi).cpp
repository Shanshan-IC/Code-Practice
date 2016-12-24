class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())    return 0;
        long long res = 0;
        bool neg = false;
        
        int i  = 0;
        while (str[i]==' ') i++;
        if (str[i]=='+')  {neg = false;i++;}
        else if(str[i]=='-')    {neg = true;i++;}
        
        for (; i<str.size(); i++) {
            if (str[i]<'0' || str[i]>'9')   break;
            res = res*10 + (str[i]-'0');
            if (neg && -res<INT_MIN)    return INT_MIN;
            if (!neg && res>INT_MAX)    return INT_MAX;
        }
        if (neg)
            return -res<INT_MIN?INT_MIN:-res;
        else
            return res>INT_MAX?INT_MAX:res;
    }
};