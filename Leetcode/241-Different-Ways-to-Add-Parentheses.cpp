class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if (input.empty())  return res;
        const int n = input.size();
        for (int i=0; i<n; i++) {
            char sign = input[i];
            if (sign =='+' || sign=='-' || sign =='*') {
                vector<int> temp1 = diffWaysToCompute(input.substr(0, i));
                vector<int> temp2 = diffWaysToCompute(input.substr(i+1));
                for (int num1:temp1) {
                    for (int num2:temp2) {
                        if (sign=='+')  res.push_back(num1+num2);
                        else if (sign=='-') res.push_back(num1-num2);
                        else    res.push_back(num1*num2);
                    }
                }
            }
        }
        if (res.empty())
            res.push_back(stoi(input));
        return res;
    }
    
};