class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);
        int len = n + m;
        int left = (len + 1) / 2;
        int low = 0, high = n;
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n)
                r1 = nums1[mid1];
            if (mid2 < m)
                r2 = nums2[mid2];

            if (mid1 - 1 >= 0)
                l1 = nums1[mid1-1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2-1];

            if(l1<=r2 && l2 <=r1) {
                if(len%2==1) return max(l1,l2);
                else return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
            }

            if(l1>r2) high=mid1-1;
            if(l2>r1) low=mid1+1;
        }
        return 0;
    }
};