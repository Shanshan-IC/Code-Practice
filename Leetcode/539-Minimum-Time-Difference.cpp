class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.empty()) return 0;
        sort(timePoints.begin(), timePoints.end());
        int res = INT_MAX;
        const int n = timePoints.size();
        int val[n] = {0};
        int val2[n] = {0};
        for (int i = 0; i<timePoints.size(); i++) {
            val[i] = stoi(timePoints[i].substr(0,2));
            val2[i] = stoi(timePoints[i].substr(3,2));
        }
        for (int i = 1; i<timePoints.size(); i++) {
            res = min(res, (val[i]-val[i-1])*60+val2[i]-val2[i-1]);
            res = min(res, (val[i-1]+24-val[i])*60+val2[i-1]-val2[i]);
        }
        res = min(res, (val[0]+24-val[n-1])*60+val2[0]-val2[n-1]);
        return res;
    }
};