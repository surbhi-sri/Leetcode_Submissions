class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j) {
        vector<int> vec(9, 0);

        for (int r=i; r < i+3; r++) {
            for (int c=j; c < j+3; c++) {
                if (board[r][c] - '0' >= 1 && board[r][c] - '0' <= 9) {
                    int ind = board[r][c] - '0' - 1;
                    if (vec[ind] == 1)
                        return 0;
                    else
                        vec[ind] = 1;
                }
            }
        }
        return 1;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> vec(9, 0);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] - '0' >= 1 && board[i][j] - '0' <= 9) {
                    if (vec[board[i][j] - '0' - 1] == 1)
                        return 0;
                    else
                        vec[board[i][j] - '0' - 1] = 1;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            vector<int> vec(9, 0);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] - '0' >= 1 && board[j][i] - '0' <= 9) {
                    if (vec[board[j][i] - '0' - 1] == 1)
                        return 0;
                    else
                        vec[board[j][i] - '0' - 1] = 1;
                }
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!check(board, i, j))
                    return 0;
            }
        }

        return 1;
    }
};