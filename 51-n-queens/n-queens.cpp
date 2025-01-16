class Solution {
public:
    bool safe(int row, int col, vector<string>& temp, int n) {
        int drow = row;
        int dcol = col;
        while (drow >= 0 && dcol >= 0) {
            if (temp[drow][dcol] == 'Q')
                return 0;
            drow--;
            dcol--;
        }

        drow = row;
        dcol = col;
        while (dcol >= 0) {
            if (temp[drow][dcol] == 'Q')
                return 0;
            dcol--;
        }

        drow = row;
        dcol = col;
        while (drow < n && dcol >= 0) {
            if (temp[drow][dcol] == 'Q')
                return 0;
            drow++;
            dcol--;
        }

        return 1;
    }

    void solve(int col, vector<string>& temp, vector<vector<string>>& ans,
               int n) {
        if (col == n) {
            ans.push_back(temp);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (safe(row, col, temp, n)) {
                temp[row][col] = 'Q';
                solve(col + 1, temp, ans, n);
                temp[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));
        solve(0, temp, ans, n);
        return ans;
    }
};