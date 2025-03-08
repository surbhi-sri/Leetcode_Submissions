class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return 1;

        else if (j == 0 && i > 0)
            return 0;

        else if (i == 0 && j > 0) {

            while (j != 0 && p[j - 1] == '*')
                j--;
                
            return j == 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);

        else if (p[j - 1] == '*')
            return dp[i][j] =
                       solve(i, j - 1, s, p, dp) | solve(i - 1, j, s, p, dp);

        else
            return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(n, m, s, p, dp);
    }
};