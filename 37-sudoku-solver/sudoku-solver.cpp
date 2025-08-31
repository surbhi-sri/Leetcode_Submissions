class Solution {
public:
     bool check(vector<vector<char>>& board, int r, int c, char ch){
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == ch)
                return 0;
            if (board[i][c] == ch)
                return 0;
            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch)
                return 0;
        }
        return 1;
     }

    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i == 9)
            return 1;
        if (j == 9)
            return solve(board, i + 1, 0);

        if (board[i][j] != '.')
            return solve(board, i, j + 1);

        for (char c = '1'; c <= '9'; c++) {
            if (check(board, i, j, c)) {
                board[i][j] = c;
                if (solve(board, i, j + 1))
                    return 1;
                board[i][j] = '.';
            }
        }

        return 0;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0); }
};