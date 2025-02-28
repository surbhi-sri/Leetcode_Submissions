class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        int mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i == 0)
                    dp[i][j] = matrix[i][j];
                else {
                    int d = dp[i - 1][j];
                    int dgr = (j + 1 < m) ? dp[i - 1][j + 1] : INT_MAX;
                    int dgl = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;

                    dp[i][j] = matrix[i][j] + min({d, dgr, dgl});
                }
                if (i == n - 1)
                    mn = min(mn, dp[i][j]);
            }
        }
        return mn;
    }
};