class Solution {
public:
    int cntzero(string& s) {
        int cnt = 0;
        for (char ch : s) {
            if (ch == '0')
                cnt++;
        }

        return cnt;
    }

    int solve(vector<string>& strs, int m, int n, int i, int len,
              vector<vector<vector<int>>>& dp) {
        if (m < 0 || n < 0)
            return -1;
        if (i == len)
            return 0;

        if (dp[i][m][n] != -1)
            return dp[i][m][n];

        int skip = solve(strs, m, n, i + 1, len, dp);
        int zero = cntzero(strs[i]);
        int one = strs[i].size() - zero;
        int take = 1 + solve(strs, m - zero, n - one, i + 1, len, dp);

        return dp[i][m][n] = max(skip, take);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp(
            len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, - 1)));
        return solve(strs, m, n, 0, len, dp);
    }
};