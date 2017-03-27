class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, l = 0, r = height.size()-1;
        while (l < r) {
            int minh = min(height[l], height[r]);
            if (minh == height[l])
                while (++l<r && height[l]<minh)
                    res += minh-height[l];
            else
                while (l<--r && height[r]<minh)
                    res += minh-height[r];
        }
        return res;
    }
};