class Solution {
public:
    void add(vector<int>& v, int r1, int r2, int c1, int c2,
             vector<vector<int>>& matrix) {
        for (int i = c1; i <= c2; i++)
            v.push_back(matrix[r1][i]);
        for (int i = r1 + 1; i <= r2; i++)
            v.push_back(matrix[i][c2]);
        if (r1 != r2) {
            for (int i = c2 - 1; i >= c1; i--)
                v.push_back(matrix[r2][i]);
        }
        if (c1 != c2) {
            for (int i = r2 - 1; i >= r1 + 1; i--)
                v.push_back(matrix[i][c1]);
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int n = matrix.size();
        int m = matrix[0].size();
        int c1 = 0, c2 = m - 1;
        int r1 = 0, r2 = n - 1;
        while (r1 <= r2 && c1 <= c2) {
            add(v, r1, r2, c1, c2, matrix);
            c1++;
            c2--;
            r1++;
            r2--;
        }
        return v;
    }
};