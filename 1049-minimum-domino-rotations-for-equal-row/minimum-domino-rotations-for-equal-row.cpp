class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int swap = 1e5;

        for (int i = 1; i <= 6; i++) {
            int found = 1;
            int topswap = 0;
            int bottomswap = 0;

            for (int j = 0; j < n; j++) {
                if (tops[j] == i) {
                    if (bottoms[j] != i)
                        bottomswap++;
                } else if (bottoms[j] == i) {
                    if (tops[j] != i)
                        topswap++;
                } else {
                    found = 0;
                    break;
                }
            }

            if (found) {
                swap = min(swap, min(topswap, bottomswap));
            }
        }

        return swap == 1e5 ? -1 : swap;
    }
};