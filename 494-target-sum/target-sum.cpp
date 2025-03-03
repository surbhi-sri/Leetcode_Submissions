class Solution {
public:
    // const int MOD = 1e9 + 7;

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += nums[i];

        sum -= target;

        if (sum < 0 || sum % 2)
            return 0;

        sum /= 2;

        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        if (nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (nums[0] != 0 && nums[0] <= sum)
            dp[0][nums[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= sum; j++) {

                int notTake = dp[i - 1][j];

                int take = 0;
                if (nums[i] <= j)
                    take = dp[i - 1][j - nums[i]];

                dp[i][j] = take + notTake;
            }
        }

        return dp[n - 1][sum];
    }
};