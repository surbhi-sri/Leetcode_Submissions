class Solution {
public:
    
    int m=1e9+7;

    int solve(int n, vector<int> &dp){
         if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;

        if(dp[n]!=-1) return dp[n];

        return dp[n]=((2 * solve(n - 1, dp)) % m + solve(n - 3, dp) % m) % m;
    }

    int numTilings(int n) {
       vector<int> dp(n+1, -1);

       return solve(n, dp);
    }
};