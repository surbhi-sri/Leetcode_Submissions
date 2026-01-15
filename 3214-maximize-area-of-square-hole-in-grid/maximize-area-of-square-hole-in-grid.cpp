class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hn = hBars.size();
        int vn = vBars.size();

        int lm = 1;
        int rm = 1;

        int cnt = 1;

        for (int i = 1; i < hn; i++) {
            if (hBars[i] == hBars[i - 1] + 1)
                cnt++;
            else
                cnt = 1;
            lm = max(lm, cnt);
        }

        cnt = 1;

        for (int i = 1; i < vn; i++) {
            if (vBars[i] == vBars[i - 1] + 1)
                cnt++;
            else
                cnt = 1;
            rm = max(rm, cnt);
        }

        int side = min(lm + 1, rm + 1);

        return side * side;
    }
};