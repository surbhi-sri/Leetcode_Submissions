class Solution {
public:
    bool ispalindrome(string& s, int i, int j) {
        if (i == j)
            return 1;
        if (i > j)
            return 0;
        while (i < j) {
            if (s[i] != s[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }

    int solve(string& s, int i, int j, vector<vector<int>>& dp) {

        if (i >= j || ispalindrome(s, i, j))
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mn = INT_MAX;

        for (int k = i; k < j; k++) {
            if (ispalindrome(s, i, k)) {

                int temp = 1;

                if (dp[k + 1][j] != -1)
                    temp += dp[k + 1][j];
                else
                    temp += solve(s, k + 1, j, dp);

                if (temp < mn)
                    mn = temp;
            }
        }
        return dp[i][j] = mn;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, n - 1, dp);
    }
};