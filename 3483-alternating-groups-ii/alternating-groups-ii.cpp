class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        int n = colors.size();

        for (int i = 0; i < k-1; i++)
            colors.push_back(colors[i]);


        n= (n+k-1);

        int cnt = 0;

        int i = 0, j = 1;

        for (int j = 1; j < n; j++) {
            if (colors[j] == colors[j - 1]) {
                i = j;
               // j++;
                continue;
            }
            if (j - i == k - 1) {
                i++;
                cnt++;
            }
        }

        return cnt;
    }
};