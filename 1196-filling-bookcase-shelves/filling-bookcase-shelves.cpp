class Solution {
public:
    int solve(int i, int width, int org_Width, int height,
              vector<vector<int>>& books, vector<vector<int>>& dp) {
        int n = books.size();
        if (i >= n)
            return height;

        if (dp[i][width] != -1)
            return dp[i][width];

        int w = books[i][0];
        int h = books[i][1];

        int ans = height + solve(i + 1, org_Width - w, org_Width, h, books, dp);

        if (width >= w) {
            int max_height = max(h, height);
            ans = min(
                ans, solve(i + 1, width - w, org_Width, max_height, books, dp));
        }

        return dp[i][width] = ans;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> dp(n + 1, vector<int>(shelfWidth + 1, -1));
        return solve(0, shelfWidth, shelfWidth, 0, books, dp);
    }
};