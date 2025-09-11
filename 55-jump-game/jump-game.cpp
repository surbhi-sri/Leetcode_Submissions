class Solution {
public:
    vector<int> dp;
    int n;

    bool solve(vector<int>& nums, int n, int idx) {
        if (idx >= n - 1)
            return 1;

        if (dp[idx] != -1)
            return dp[idx];

        for (int i = 1; i <= nums[idx]; i++) {
            if (solve(nums, n, i + idx))
                return dp[idx] = 1;
        }
        return dp[idx] = 0;
    }

    bool canJump(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, -1);
        return solve(nums, n, 0);
    }
};