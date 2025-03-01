class Solution {
public:
    bool solve(int n, int target, vector<int> nums) {
        vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        // if (nums[0] <= target)
        //     dp[0][nums[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {

                bool notTake = dp[i - 1][j];
                bool take = 0;
                if (j >= nums[i])
                    take = dp[i - 1][j - nums[i]];

                dp[i][j] = take | notTake;
            }
        }

        return dp[n - 1][target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int target = 0;
        for (int i = 0; i < n; i++)
            target += nums[i];

        if (target % 2)
            return 0;

        target /= 2;

        return solve(n, target, nums);
    }
};