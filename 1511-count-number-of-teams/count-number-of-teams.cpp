class Solution {
public:
    int numTeams(vector<int>& rating) {
        int cnt = 0;
        int n = rating.size();
        for (int i = 0; i < n; i++) {
            int m1 = rating[i];
            for (int j = i + 1; j < n; j++) {
                if (rating[j] <= m1)
                    continue;
                int m2 = rating[j];
                for (int k = j + 1; k < n; k++) {
                    if (rating[k] <= m2)
                        continue;
                    else
                        cnt++;
                }
            }
        }
         for (int i = 0; i < n; i++) {
            int m1 = rating[i];
            for (int j = i + 1; j < n; j++) {
                if (rating[j] >= m1)
                    continue;
                int m2 = rating[j];
                for (int k = j + 1; k < n; k++) {
                    if (rating[k] >= m2)
                        continue;
                    else
                        cnt++;
                }
            }
        }
        return cnt;
    }
};