class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())  return true;
        int left=0, right = s.size()-1;
        while (left<right) {
            while (left<right && !isalnum(s[left]))   left++;
            while (left<right && !isalnum(s[right]))  right--;
            if (left>=right)    break;
            if (tolower(s[left]) != tolower(s[right]))  return false;
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};