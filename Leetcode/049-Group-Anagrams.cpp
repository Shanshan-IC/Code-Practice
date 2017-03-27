class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty())   return res;
        unordered_map<string, vector<string>> table;
        for (string str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            table[key].push_back(str);
        }
        for (auto i=table.begin(); i!=table.end(); i++) 
            res.push_back(i->second);
        return res;
    }
};