class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
       int n= triangle.size();
       if(n==1) return triangle[0][0];

      vector<int> dp(n, 0);

       for(int i=0; i<n; i++)
       dp[i]=triangle[n-1][i];

       for(int r=n-2; r>=0; r--){
          for(int c=0; c<=r; c++){
            dp[c]=triangle[r][c] + min(dp[c], dp[c+1]);
          }
       }

       return dp[0];
    }
};