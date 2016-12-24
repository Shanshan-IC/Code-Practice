class Solution {
public:
    int countPrimes(int n) {
        vector<int> p(n, 1);
        int ans = 0;
        for (int i=2; i<n; i++) {
            ans += p[i];
            if (p[i]==1)
                for (int j=i; j<n; j+=i)
                    p[j] = 0;
        }
        return ans;
    }
};