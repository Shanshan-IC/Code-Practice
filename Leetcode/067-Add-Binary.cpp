class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty())  return b;
        if (b.empty())  return a;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = 0, j = 0, carry = 0;
        string res = "";
        while (i<a.size() || j<b.size()) {
            if (i<a.size())
                carry += a[i++]-'0';
            if (j<b.size())
                carry += b[j++]-'0';
            res += (char)(carry%2+'0');
            carry /= 2;
        }
        if (carry)  res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};