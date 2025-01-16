class Solution {
public:
    void solve(int col, vector<string>& temp, vector<vector<string>>& ans,
               int n, vector<int> &back, vector<int> &upper_dig,
               vector<int> &lower_dig) {

        if (col == n) {
            ans.push_back(temp);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (back[row] == 0 && lower_dig[row + col] == 0 &&
                upper_dig[n - 1 + col - row] == 0) {
                temp[row][col] = 'Q';
                back[row] = 1;
                lower_dig[row + col] = 1;
                upper_dig[n - 1 + col - row] = 1;
                solve(col+1, temp, ans, n, back, upper_dig, lower_dig);
                temp[row][col] = '.';
                back[row] = 0;
                lower_dig[row + col] = 0;
                upper_dig[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));
        vector<int> back(n, 0);
        vector<int> upper_dig(2 * n - 1, 0);
        vector<int> lower_dig(2 * n - 1, 0);
        solve(0, temp, ans, n, back, upper_dig, lower_dig);
        return ans;
    }
};