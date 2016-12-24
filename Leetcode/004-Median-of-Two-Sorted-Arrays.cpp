class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        int k = (m+n)/2;
        if ((m+n)%2!=0)
            return helper(nums1, nums2, k+1);
        else
            return (helper(nums1, nums2, k) + helper(nums1, nums2, k+1))/2;
    }
    
    double helper(vector<int> &nums1, vector<int> &nums2, int k) {
        const int m = nums1.size();
        const int n = nums2.size();
        if (m>n)    return helper(nums2, nums1, k);
        if (m==0)   return nums2[k-1];
        if (k==1)   return min(nums1[0], nums2[0]);
        
        int pa = min(m, k/2), pb = k-pa;
        if (nums1[pa-1] < nums2[pb-1]) {
            vector<int> a(nums1.begin()+pa, nums1.end());
            return helper(a, nums2, k-pa);
        }
        else {
            vector<int> b(nums2.begin()+pb, nums2.end());
            return helper(nums1, b, k-pb);
        }
        
    }
};