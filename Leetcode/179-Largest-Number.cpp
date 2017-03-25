class Solution {
public:
    string largestNumber(vector<int>& nums) {
        const int n = nums.size();
        vector<string> str(n);
        for (int i=0; i<n; i++)
            str[i] = to_string(nums[i]);
        sort(str.begin(), str.end(), [](string &i, string &j){return i+j>j+i;});
        string res;
        for (string s:str)  res+=s;
        return res[0]=='0'?"0":res;
    }
};