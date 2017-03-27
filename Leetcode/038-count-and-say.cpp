class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i=0; i<n-1; i++)
            s = getNext(s);
        return s;
    }
    
    string getNext(string s) {
        const int n = s.size();
        int count = 1;
        char temp = s[0];
        string res = "";
        for (int i=1; i<n; i++) {
            if (s[i]==s[i-1])   count++;
            else {
                res = res + char(count+int('0')) +temp;
                temp = s[i];
                count = 1;
            }
        }
        res = res + char(count+int('0')) +temp;
        return res;
    }
};