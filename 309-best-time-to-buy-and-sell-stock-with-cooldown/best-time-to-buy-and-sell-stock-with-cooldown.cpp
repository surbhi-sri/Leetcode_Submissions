class Solution {
public:
    int solve(int ind, int buy, int n, vector<int>& prices,
              vector<vector<int>>& dp) {
        if (ind >= n)
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit = 0;

        if (buy)
            profit = max(-prices[ind] + solve(ind+1, 0, n, prices, dp),
                         solve(ind+1, 1, n, prices, dp));
        else
            profit = max(prices[ind] + solve(ind+2, 1, n, prices, dp),
                         solve(ind+1, 0, n, prices, dp));

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1)
            return 0;

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 1, n, prices, dp);
    }
};