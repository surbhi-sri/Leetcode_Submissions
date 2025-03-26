class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> vec;
        int reminder = grid[0][0] % x;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] % x != reminder)
                    return -1;

                vec.push_back(grid[i][j]);
            }
        }

        sort(vec.begin(), vec.end());
        n = vec.size();

        vector<int> lsum(n, 0);
        vector<int> rsum(n, 0);

        int suml = 0;
        int sumr = 0;

        for (int i = 0; i < vec.size(); i++) {
            suml += vec[i];
            sumr += vec[n - i - 1];

            lsum[i] = suml;
            rsum[n - i - 1] = sumr;
        }

        int l = 0, r = n - 1;
        int mn = INT_MAX;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int operation = 0;

            if (mid>0) {
                operation += (vec[mid] * mid - lsum[mid - 1]) / x;
            }

            if (mid + 1 < n) {
                operation += (rsum[mid + 1] - vec[mid] * (n - mid-1)) / x;
            }

            if (operation < mn)
                mn = operation;

            if (mid > 0 && vec[mid] - vec[mid - 1] > x) {
                r = mid - 1; 
            } else {
                l = mid + 1; 
            }
        }

        return mn;
    }
};