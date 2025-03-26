class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> vec;
        int reminder = grid[0][0] % x;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] % x != reminder)
                    return -1;

                vec.push_back(grid[i][j]);
            }
        }

        sort(vec.begin(), vec.end());
        n = vec.size();

        int target = vec[n / 2];
        int operation = 0;

        for (int& num : vec) {
            operation += abs(target - num) / x;
        }

        return operation;
    }
};