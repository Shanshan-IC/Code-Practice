class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        map<string, int> word;
        map<string, int> curr;
        for (string str: words) word[str]++;
        int m = words[0].size();
        int n = words.size();
        if (s.size()<m*n)   return res;
        for (int i=0; i<=s.size()-m*n; i++) {
            curr.clear();
            int j = 0;
            for (j=0; j<n; j++) {
                string temp = s.substr(i+j*m, m);
                if (word.find(temp)==word.end())    break;
                curr[temp]++;
                if (curr[temp]>word[temp])  break;
            }
            if (j==n)   res.push_back(i);
        }
        return res;
    }
};