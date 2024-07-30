class Solution {
public:
    const int MOD = 1e9 + 7;

    int findTargetSumWays(vector<int>& nums, int target) {
        
            int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        sum += target;

        if (sum % 2 || sum < 0)
            return 0;
        sum /= 2;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j < nums[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] =
                        (dp[i - 1][j - nums[i - 1]] + dp[i - 1][j]) % MOD;
            }
        }

        return dp[n][sum];
    }
};