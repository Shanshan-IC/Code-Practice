class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.empty())  return res;
        sort(intervals.begin(), intervals.end(), [](Interval &i, Interval &j){return i.start<j.start;});
        const int n = intervals.size();
        for (int i=0; i<n; i++) {
            if (i+1<n && intervals[i+1].start<=intervals[i].end) {
                intervals[i+1].end = max(intervals[i].end, intervals[i+1].end);
                intervals[i+1].start = min(intervals[i].start, intervals[i+1].start);
            }
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};