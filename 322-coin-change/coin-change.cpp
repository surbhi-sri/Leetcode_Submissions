class Solution {
public:
    int countMn(int n, vector<int>& coins, int amount,
                vector<vector<int>>& dp) {

        if (n == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9;
        }

        if (dp[n][amount] != -1)
            return dp[n][amount];

        int notTake = countMn(n - 1, coins, amount, dp);

        int take = INT_MAX;

        if (coins[n] <= amount)

            take = 1 + countMn(n, coins, amount - coins[n], dp);

        return dp[n][amount] = min(notTake, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int cnt = countMn(n - 1, coins, amount, dp);

        return cnt > 1e4 ? -1 : cnt;
    }
};