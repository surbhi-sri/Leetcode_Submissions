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

        auto findSum = [&](int i, int j, int k) {
            int sum = preSum[i + k][j + k];
            if (i > 0)
                sum -= preSum[i - 1][j + k];
            if (j > 0)
                sum -= preSum[i + k][j - 1];
            if (j > 0 && i > 0)
                sum += preSum[i - 1][j - 1];
            return sum;
        };

        auto check = [&](int side) {
            for (int i = 0; i + side - 1 < n; i++) {
                for (int j = 0; j + side - 1 < m; j++) {

                    int val = findSum(i, j, side-1);
                    if (val <= threshold)
                        return 1;
                }
            }
            return 0;
        };

        int bestSide = 0;

        int low = 1;
        int high = min(m, n);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                bestSide = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }

        return bestSide;
    }
};