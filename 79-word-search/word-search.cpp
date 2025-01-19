class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& board, string &word, int ind,
               int m, int n) {
        if (ind == word.length())
            return 1;

        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '!' || board[i][j] != word[ind])
            return 0;

        char c = board[i][j];
        board[i][j] = '!';

        bool right = solve(i, j + 1, board, word, ind + 1, m, n);
        bool down = solve(i + 1, j, board, word, ind + 1, m, n);
        bool left = solve(i, j - 1, board, word, ind + 1, m, n);
        bool top = solve(i - 1, j, board, word, ind + 1, m, n);

        board[i][j] = c;

        return (right || down || left || top);
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(i, j, board, word, 0, m, n) == 1)
                        return true;
                }
            }
        }

        return false;
    }
};