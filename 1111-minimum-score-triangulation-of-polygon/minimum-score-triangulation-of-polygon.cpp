class Solution {
public:
    int solve(vector<int>& values, int i, int j, vector<vector<int>> &dp) {
        if (j - i < 2)
            return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int score = INT_MAX;

        for (int k = i + 1; k < j; k++) {
            int weight = solve(values, i, k, dp) +
                         values[i] * values[k] * values[j] +
                         solve(values, k, j, dp);
            score = min(weight, score);
        }

        return dp[i][j] = score;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(values, 0, n - 1, dp);
    }
};