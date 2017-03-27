class Solution {
public:
    string multiply(string num1, string num2) {
        const int m = num1.size();
        const int n = num2.size();
        string res(m+n+1, '0');
        for (int i=m-1; i>=0; i--)
            for (int j=n-1; j>=0; j--) {
                int temp = (num1[i]-'0')*(num2[j]-'0') + (res[i+j+2]-'0');
                res[i+j+2] = '0'+temp%10;
                res[i+j+1] += temp/10;
            }
        size_t begin = res.find_first_not_of('0');
        if(begin == string::npos) return "0";
        return res.substr(begin);        
    }
};