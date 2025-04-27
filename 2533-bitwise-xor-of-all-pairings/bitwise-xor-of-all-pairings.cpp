class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int xorr = 0;
        if (m % 2){
            for(int i=0; i<n; i++)
            xorr ^=nums1[i];
        }
 
        if (n % 2){
            for(int i=0; i<m; i++)
            xorr ^=nums2[i];
        }

        return xorr;

    }
};