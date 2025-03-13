class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp = matrix;

        int n = matrix.size();
        int m = matrix[0].size();

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == 0|| i==0 || j==0)
                    dp[i][j] = matrix[i][j];
                else
                    dp[i][j] =
                        1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});

                 cnt+=dp[i][j];       
            }
        }

        return cnt;
    }
};