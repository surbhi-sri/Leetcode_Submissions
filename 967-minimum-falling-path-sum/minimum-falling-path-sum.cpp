class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> dp(matrix[0]);
        int mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            vector<int> temp(m, 0);
            for (int j = 0; j < m; j++) {
                if (i == 0){
                    dp[j] = matrix[i][j];
                    temp[j] = matrix[i][j];
                    }
                else {
                    int d = dp[j];
                    int dgr = (j + 1 < m) ? dp[j + 1] : INT_MAX;
                    int dgl = (j > 0) ? dp[j - 1] : INT_MAX;

                    temp[j] = matrix[i][j] + min({d, dgr, dgl});
                }
                if (i == n - 1)
                    mn = min(mn, temp[j]);
            }
            dp = temp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};