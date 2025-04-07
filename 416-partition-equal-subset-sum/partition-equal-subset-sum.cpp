class Solution {
public:
    bool solve(int ind, int sum, vector<int>& nums, vector<vector<int>>& dp, int n) {
        if(sum==0) return 1;

        if (ind >= n)
            return sum == 0;

        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        int notTake = solve(ind + 1, sum, nums, dp, n);
        int take = 0;

        if (sum >= nums[ind])
            take = solve(ind + 1, sum - nums[ind], nums, dp, n);

        return dp[ind][sum] = (take || notTake);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2 == 1)
            return 0;

        sum /= 2;

        vector<vector<int>> dp(n+1 , vector<int>(sum+1, -1));

        return solve(0, sum, nums, dp, n);
    }
};