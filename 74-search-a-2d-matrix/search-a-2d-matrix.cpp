class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        for ( i = 0; i < n; i++) {
            if (matrix[i][0] == target)
                return 1;
            if (matrix[i][0] > target)
                break;
        }

        if (i == 0)
            return 0;

        i--;
        int left = 0, right = m - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (matrix[i][mid] == target)
                return 1;
            else if (matrix[i][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return 0;
    }
};