class Solution {
public:
    typedef long long ll;
    vector<ll> bitcnt;

    void getbitscnt(ll num) {

        if (num == 0)
            return;

        if (num == 1) {
            bitcnt[0] += 1;
            return;
        }

        if (num == 2) {
            bitcnt[0] += 1;
            bitcnt[1] += 1;
            return;
        }

        ll bitlen = log2(num);
        ll nearpower2 = (1ll << bitlen); // pow(2, bitlen);
        bitcnt[bitlen] += (num - nearpower2 + 1);

        for (ll i = 0; i < bitlen; i++)
            bitcnt[i] += (nearpower2 / 2);

        num = num - nearpower2;

        getbitscnt(num);
    }

    long long findMaximumNumber(long long k, int x) {
        ll left = 0;
        ll right = 1e15;

        ll res = 0;

        while (left <= right) {
            ll mid = left + (right - left) / 2;
            bitcnt = vector<ll>(65, 0);
            getbitscnt(mid);

            ll totalprice = 0;

            for (ll i = 0; i < log2(mid) + 1; i++) {
                if ((i + 1) % x == 0) {
                    totalprice += bitcnt[i];
                }
            }

            if (totalprice <= k) {
                res = mid;
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return res;
    }
};