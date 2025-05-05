class Solution {
public:
    int solve(int i, int j, int n, int m) {
        if (i == n - 1 && j == m - 1)
            return 1;

        if (i > n || j > m)
            return 0;

        return solve(i + 1, j, n, m) + solve(i, j + 1, n, m);
    }

    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n, vector<int>(m, 0));
        dp[n-1][m-1]=1;
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
              if(i+1<n) dp[i][j] +=dp[i+1][j];
              if(j+1<m) dp[i][j] +=dp[i][j+1];
            }
        }

        return dp[0][0];
        
        }
};