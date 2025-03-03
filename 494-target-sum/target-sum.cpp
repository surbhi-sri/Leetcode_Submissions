class Solution {
public:
    const int MOD = 1e9 + 7;

    int count(int n, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if (n == 0) {
            if (arr[0] == 0 && sum == 0)
                return 2;
            if (sum == 0 || sum == arr[0])
                return 1;
            return 0;
        }

        if (dp[n][sum] != -1)
            return dp[n][sum];

        int notTake = count(n - 1, sum, arr, dp);
        int take = 0;

        if (arr[n] <= sum)
            take = count(n - 1, sum - arr[n], arr, dp);

        return dp[n][sum] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += nums[i];

        sum -= target;

        if (sum < 0 || sum % 2)
            return 0;

        sum /= 2;

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return count(n - 1, sum, nums, dp);
    }
};