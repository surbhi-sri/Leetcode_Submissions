class Solution {
public:
    int m = 1e9 + 7;
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        ll xorra = 0;
        ll xorrb = 0;

        for (int i = 49; i >= n; i--) {
            bool a_ith_bit = ((a >> i) & 1) > 0;
            bool b_ith_bit = ((b >> i) & 1) > 0;

            if (a_ith_bit)
                xorra = xorra ^ (1ll << i);
            if (b_ith_bit)
                xorrb = xorrb ^ (1ll << i);
        }

        for (int i = n - 1; i >= 0; i--) {
            bool a_ith_bit = ((a >> i) & 1) > 0;
            bool b_ith_bit = ((b >> i) & 1) > 0;

            if (a_ith_bit == b_ith_bit) {
                xorra = xorra ^ (1ll << i);
                xorrb = xorrb ^ (1ll << i);
            } else {
                if (xorra > xorrb)
                    xorrb = xorrb ^ (1ll << i);
                else
                    xorra = xorra ^ (1ll << i);
            }
        }

        xorra = xorra % m;
        xorrb = xorrb % m;

        return (xorra * xorrb) % m;
    }
};