class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n <=1)
            return n;

        vector<long long> f(31, 0);

        f[0] = 1;
        for (int i = 1; i < 31; i++)
            f[i] = 2 * f[i - 1] + 1;

        int res = 0;
        int sign = 1;

        for (int i = 30; i >= 0; i--) {
            int ith_bit = ((n >> i) & 1) > 0;

            if (ith_bit != 0) {
                if (sign > 0) {
                    res += f[i];
                    sign = !sign;
                } else {
                    res -= f[i];
                    sign = !sign;
                }
            }
        }
        return res;
    }
};