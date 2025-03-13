class Solution {
public:
    int solve(int ind, int k, int n, vector<int>& arr, vector<int>& dp) {

        if (ind == n)
            return 0;

        if (dp[ind]!= -1)
            return dp[ind];

        int mx = INT_MIN;
        int maxi_part = INT_MIN;
        int len = 0;

        for (int i = ind; i < min(ind + k, n); i++) {

            mx = max(mx, arr[i]);
            len++;

            int part = mx * len + solve(i + 1, k, n, arr, dp);

            if (part > maxi_part)
                maxi_part = part;
        }

        return dp[ind] = maxi_part;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n + 1, -1);

        return solve(0, k, n, arr, dp);
    }
};