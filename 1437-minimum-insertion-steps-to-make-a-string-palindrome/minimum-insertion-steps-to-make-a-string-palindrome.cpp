class Solution {
public:
    int solve(string& s, string& t, int i, int j, int n,  vector<vector<int>> &dp) {
        if (i == n || j == n)
            return dp[i][j] = 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = 1 + solve(s, t, i + 1, j + 1, n, dp);
        else
            return dp[i][j] =
                       max(solve(s, t, i + 1, j, n, dp), solve(s, t, i, j + 1, n, dp));
    }

    int minInsertions(string s) {
        int n = s.size();
        if (n < 2)
            return 0;

        string t = s;
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return n - solve(s, t, 0, 0, n, dp);
    }
};