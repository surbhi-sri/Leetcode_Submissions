class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int i = 0, j = 0;
        int  w = 0, mn = 100;
        int n = blocks.size();

        for (int i = 0; i < n; i++) {

            if (blocks[i] == 'W')
                w++;

            if (i >= k - 1) {
                if (w < mn)
                    mn = w;
                if (blocks[j] == 'W')
                    w--;
                j++;
            }
        }

        return mn;
    }
};