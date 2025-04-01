class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {

        int n = questions.size();

        vector<long long> dp(n + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            long long notTake = dp[ind + 1];

            long long take = questions[ind][0];

            if (ind + questions[ind][1] + 1 <= n)
                take += dp[ind + questions[ind][1] + 1];

            dp[ind] = max(take, notTake);
        }

        return dp[0];
    }
};