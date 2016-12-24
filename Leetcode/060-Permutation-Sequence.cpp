class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> input(n);
        for (int i=1; i<=n; i++)
            input[i-1] = i;
        k--;
        string res;
        while (input.size()>1) {
            int f = fac(input.size()-1);
            int pos = k/f;
            res += input[pos] +'0';
            input.erase(input.begin()+pos);
            k %= f;
        }
        res += input[0] +'0';
        return res;
    }
    
    int fac(int n) {
        if (n==0)   return 1;
        int res = 1;
        for (int i=1; i<=n; i++)
            res *= i;
        return res;
    }
};
