class Solution {
public:
    bool isSquare(vector<vector<int>>& matrix, int r, int c, int size) {

        for (int i = r; i < r + size; i++) {
            for (int j = c; j < c + size; j++) {
                if (matrix[i][j] == 0)
                    return 0;
            }
        }

        return 1;
    }

    int countSquares(vector<vector<int>>& matrix) {

        int cnt = 0;

        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                for (int size = 1; (size + i <= n && size + j <= m); size++) {
                    if (isSquare(matrix, i, j, size))
                        cnt++;
                }
            }
        }

        return cnt;
    }
};