class Solution {
public:
    void reverseWords(string &s) {
        istringstream input(s);
        string res, temp;
        while(input>>temp) 
            res = " "+ temp + res;
        s = res.empty()?res: res.substr(1);
    }
};