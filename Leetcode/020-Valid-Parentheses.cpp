class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.empty())  return true;
        for (int i=0; i<s.size(); i++) {
            char sign = s[i];
            if (s[i]=='[' || s[i]=='(' || s[i]=='{')
                st.push(sign);
            else {
                if (st.empty()) return false;
                if (sign==')') {
                    if (st.top() != '(')    return false;
                    else    st.pop();
                }
                else if (sign==']') {
                    if (st.top() != '[')    return false;
                    else    st.pop();
                }
                else {
                    if (st.top() != '{')    return false;
                    else    st.pop();
                }
            }
        }
        return st.size()==0;
    }
};