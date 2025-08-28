class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>> mp;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[j - i].push_back(grid[i][j]);
            }
        }

        for (auto it : mp) {
            int key = it.first;
            if (key > 0)
                sort(mp[key].begin(), mp[key].end());
            else
                sort(mp[key].rbegin(), mp[key].rend());
        }

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                ans[i][j] = mp[j - i].back();
                mp[j - i].pop_back();
            }
        }

        return ans;
    }
};