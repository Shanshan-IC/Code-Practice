class Solution {
public:
    int longestValidParentheses(string input) {
        if (input.empty())  return 0;
        stack<int> st;
        int last = -1;
        int res = 0;
        for (int i=0; i<input.size(); i++) {
            if (input[i]=='(')  st.push(i);
            else {
                if (st.empty()) last = i;
                else {
                    st.pop();
                    if (st.empty()) res = max(res, i-last);
                    else    res = max(res, i-st.top());
                }
            }
        }
        return res;
    }
};