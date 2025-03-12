class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        cuts.push_back(0);
        cuts.push_back(n);

        sort(begin(cuts), end(cuts));

        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        for (int i = c; i >= 1; i--) {
            for (int j = 1; j <= c; j++) {
              
                if (i > j)
                    continue;

                int cost = INT_MAX;

                for (int k = i; k <= j; k++) {
                    int cut =
                        cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];

                    cost = min(cut, cost);
                }

                dp[i][j] = cost;
            }
        }

        return dp[1][c];
    }
};