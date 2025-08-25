class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> mp;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mp[i + j].push_back(mat[i][j]);

        vector<int> ans;

        for (auto& it : mp) {
            int key = it.first;
            vector<int> temp = it.second;

            if (key % 2 == 0)
                reverse(temp.begin(), temp.end());

            for (int& num : temp)
                ans.push_back(num);
        }

        return ans;
    }
};