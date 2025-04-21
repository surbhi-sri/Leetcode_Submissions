class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();

        long long ele = 0;
        long long mx = 0, mn = 0;

        for (int i = 0; i < n; i++) {
            ele += differences[i];

            mx = max(mx, ele);
            mn = min(mn, ele);
        }

        int cnt = (upper - mx + mn - lower + 1);

        if (cnt <= 0)
            return 0;
        return cnt;
    }
};