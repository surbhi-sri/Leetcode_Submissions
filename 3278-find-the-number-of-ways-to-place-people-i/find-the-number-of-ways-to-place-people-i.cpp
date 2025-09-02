class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int pair = 0;

        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> row(51, 0);
        vector<int> col(51, 0);

        for (int i = 0; i < n; i++) {
            row[points[i][0]] = 1;
            col[points[i][1]] = 1;
        }

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; j++) {

                int x2 = points[j][0], y2 = points[j][1];

                if (y2 > y1)
                    continue;

                if (y2 > maxY) {
                    pair++;
                    maxY = y2;
                }
            }
        }

        return pair;
    }
};