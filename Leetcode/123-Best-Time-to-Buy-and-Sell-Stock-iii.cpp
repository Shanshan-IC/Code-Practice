class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if (n<2)    return 0;
        vector<int> preProfits(n, 0);
        vector<int> postProfits(n, 0);
        int minP = prices[0];
        for (int i=1; i<n; i++) {
            minP = min(minP, prices[i]);
            preProfits[i] = max(preProfits[i-1], prices[i]-minP);
        }
        int maxP = prices[n-1];
        for (int i=n-2; i>=0; i--) {
            maxP = max(maxP, prices[i]);
            postProfits[i] = max(postProfits[i+1], maxP-prices[i]);
        }
        int res = 0;
        for (int i=0; i<n; i++)
            res = max(res, preProfits[i]+postProfits[i]);
        return res;
    }
};