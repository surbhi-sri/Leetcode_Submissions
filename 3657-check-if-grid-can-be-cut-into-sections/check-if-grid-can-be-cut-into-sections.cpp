class Solution {
public:
    bool overlap(vector<vector<int>>& interval, int length) {

        sort(begin(interval), end(interval));

        int n = interval.size();
        int e = interval[0][1];
         int cut=0;
        for (int i = 1; i < n; i++) {
            if (e > interval[i][0])
               e = max(e, interval[i][1]);
            else{
               cut++;
               e=interval[i][1];
        }
    }
        return  cut>=2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {

        vector<vector<int>> row;
        vector<vector<int>> col;

        int m = rectangles.size();

        for (int i = 0; i < m; i++) {
            row.push_back({rectangles[i][0], rectangles[i][2]});
            col.push_back({rectangles[i][1], rectangles[i][3]});
        }

       if(overlap(row, n)) return 1;
       return overlap(col, n);
    }
};