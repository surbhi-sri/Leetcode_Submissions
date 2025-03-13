class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--) {

            int mx = INT_MIN;
            int maxi_part = INT_MIN;
            int len = 0;

            for (int i = ind; i < min(ind + k, n); i++) {

                mx = max(mx, arr[i]);
                len++;

                int part = mx * len + dp[i + 1];

                if (part > maxi_part)
                    maxi_part = part;
            }

             dp[ind] = maxi_part;
        }

        return dp[0];
    }
};