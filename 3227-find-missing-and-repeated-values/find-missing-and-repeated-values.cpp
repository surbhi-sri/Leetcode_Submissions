class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mp[grid[i][j]]++;

        int repeat = 0, missing = 0;
        for (int i = 1; i <= n * n; i++) {
            if (mp[i] == 2)
                repeat = i;
            else if (mp[i] == 0)
                missing = i;

            if (missing && repeat)
                break;
        }

        return {repeat, missing};
    }
};