class Solution {
public:
    int solve(int ind, int buy, int n, int cap, vector<int>& prices,
              vector<vector<vector<int>>> &dp) {
        if (ind==n || cap == 0)
            return 0;

        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        int profit = 0;

        if (buy)
            profit = max(-prices[ind] + solve(ind + 1, 0, n, cap, prices, dp),
                         solve(ind + 1, 1, n, cap, prices, dp));
        else
            profit = max(prices[ind] + solve(ind + 1, 1, n, cap - 1, prices, dp),
                    solve(ind + 1, 0, n, cap, prices, dp));

        return dp[ind][buy][cap] = profit;
}

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

       vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));;
        return solve(0, 1, n, 2, prices, dp);
    }
};