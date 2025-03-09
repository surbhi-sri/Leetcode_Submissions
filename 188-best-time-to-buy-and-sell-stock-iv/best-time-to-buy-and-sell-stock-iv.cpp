class Solution {
public:
    int solve(int ind, int buy, int n, int k, vector<int>& prices, vector<vector<vector<int>>> &dp) {
        if (ind == n || k == 0)
            return 0;

        if (dp[ind][buy][k] != -1)
            return dp[ind][buy][k];

        int profit = 0;

        if (buy)
            profit = max(-prices[ind] + solve(ind + 1, 0, n, k, prices, dp),
                         solve(ind + 1, 1, n, k, prices, dp));
        else
            profit = max(prices[ind] + solve(ind + 1, 1, n, k - 1, prices, dp),
                         solve(ind + 1, 0, n, k, prices, dp));

        return dp[ind][buy][k] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));

        return solve(0, 1, n, k, prices, dp);
    }
};