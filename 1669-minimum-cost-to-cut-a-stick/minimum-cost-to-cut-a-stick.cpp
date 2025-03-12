class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int cost = INT_MAX;

        for (int k = i; k <= j; k++) {
            int cut = cuts[j + 1] - cuts[i - 1] + solve(i, k-1, cuts, dp) +
                      solve(k+1, j, cuts, dp);

           cost=min(cut, cost);
        }

        return dp[i][j]=cost;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        cuts.push_back(0);
        cuts.push_back(n);

        sort(begin(cuts), end(cuts));

        vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));

        return solve(1, c, cuts, dp);
    }
};