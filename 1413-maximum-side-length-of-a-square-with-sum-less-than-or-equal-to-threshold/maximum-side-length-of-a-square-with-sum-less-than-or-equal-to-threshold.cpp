class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> preSum(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                preSum[i][j] = (i > 0 ? preSum[i - 1][j] : 0) +
                               (j > 0 ? preSum[i][j - 1] : 0) -
                               ((i > 0 && j > 0) ? preSum[i - 1][j - 1] : 0) +
                               mat[i][j];
            }
        }

        auto findSum =
            [&](int i, int j, int k) {
                int sum = preSum[i + k][j + k];
                if (i > 0)
                    sum -= preSum[i - 1][j + k];
                if (j > 0)
                    sum -= preSum[i + k][j - 1];
                if (j > 0 && i > 0)
                    sum += preSum[i - 1][j - 1];
                return sum;
            };

        int bestSide = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                for (int k = 0; k < min(n - i, m - j); k++) { // offset

                    int val = findSum(i, j, k);
                    if (val <= threshold)
                        bestSide = max(bestSide, k + 1);
                    else
                        break;
                }
            }
        }

        return bestSide;
    }
};