class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2 == 1)
            return 0;

        sum /= 2;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;
            

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= sum; j++) {

                int notTake = dp[i + 1][j];
                int take = 0;

                if (j >= nums[i])
                    take = dp[i + 1][j-nums[i]];

                 dp[i][j] = (take || notTake);
            }
        }

        return dp[0][sum];
    }
};