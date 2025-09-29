class Solution {
public:
    int n;
    int dp[50][50];
    int solve(int i, int j, vector<int>& values) {
        if (j - i + 1 < 3)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int wt = solve(i, k, values) + (values[i] * values[j] * values[k]) +
                     solve(k, j, values);
            ans = min(ans, wt);
        }
        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        n = values.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n - 1, values);
    }
};