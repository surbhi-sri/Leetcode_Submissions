class Solution {
public:
    int n, m;
    int solve(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp) {
        if (i >= n || j >= m || mat[i][j] == 0)
            return dp[i][j] = 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(mat, i, j + 1, dp);
        int dig = solve(mat, i + 1, j + 1, dp);
        int down = solve(mat, i + 1, j, dp);

        return dp[i][j] = 1 + min({right, dig, down});
    }
    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0)
                    continue;
                res += solve(matrix, i, j, dp);
            }
        }

        return res;
    }
};