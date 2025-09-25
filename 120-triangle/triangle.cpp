class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
       int n= triangle.size();
       if(n==1) return triangle[0][0];

       vector<vector<int>> dp(n, vector<int>(n, 0));

       for(int i=0; i<n; i++)
       dp[n-1][i]=triangle[n-1][i];

       for(int r=n-2; r>=0; r--){
          for(int c=r; c>=0; c--){
            dp[r][c]=triangle[r][c] + min(dp[r+1][c], dp[r+1][c+1]);
          }
       }

       return dp[0][0];
    }
};