class Solution {
public:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mx = INT_MIN;
        for (int k = i; k < j; k++) {
            int temp = solve(arr, i, k, dp) + solve(arr, k + 1, j, dp) +
                       arr[i - 1] * arr[k] * arr[j];
            mx = max(mx, temp);
        }
        return dp[i][j] = mx;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(nums, 1, n - 1, dp);
    }
};