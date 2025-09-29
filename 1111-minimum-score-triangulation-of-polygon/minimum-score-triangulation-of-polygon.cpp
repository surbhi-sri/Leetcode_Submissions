class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int i = 0, j = n - 1;

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    int weight =
                        dp[i][k] + values[i] * values[k] * values[j] + dp[k][j];
                    dp[i][j] = min(weight, dp[i][j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};