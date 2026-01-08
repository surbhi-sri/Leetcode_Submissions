
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int n1, int n2,
              vector<vector<int>>& dp) {
        if (n1 < 0 || n2 < 0)
            return -1e9;

        if (dp[n1][n2] != -1e9)
            return dp[n1][n2];

        int val = nums1[n1] * nums2[n2];
        int nxt_ij = solve(nums1, nums2, n1 - 1, n2 - 1, dp) + val;
        int nxt_i = solve(nums1, nums2, n1 - 1, n2, dp);
        int nxt_j = solve(nums1, nums2, n1, n2 - 1, dp);

        return dp[n1][n2]=max({val, nxt_ij, nxt_i, nxt_j});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1000000000));

        return solve(nums1, nums2, n1 - 1, n2 - 1, dp);
    }
};