class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
         if(n==0) return 0;

         if(n==1) return nums[0];

        vector<int> dp(n, 0);

        dp[0] = nums[0];

        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if (i > 1)
                take += dp[i - 2];
            int not_take = nums[i - 1];
            if (i - 1 >1)
                not_take += dp[i - 3];

            dp[i] = max(take, not_take);
        }

        return dp[n - 1];
    }
};
