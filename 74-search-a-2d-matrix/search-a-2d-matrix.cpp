class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        if (n == 1 && m == 1)
            return matrix[0][0] == target;

        int low = 0, high = m * n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m, col = mid % m;
            if (matrix[row][col] == target)
                return 1;
            if (matrix[row][col] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return 0;
    }
};