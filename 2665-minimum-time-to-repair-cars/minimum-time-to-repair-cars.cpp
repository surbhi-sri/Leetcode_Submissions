class Solution {
public:
    typedef long long ll;

    bool isPossible(vector<int>& ranks, int cars, ll time) {
        ll cnt = 0;

        for (int r : ranks) {
            ll n2 = time / r;
            cnt += (1LL)*sqrt(n2);
        }

        return (cnt >= cars);
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();

        ll l = 1;
        int min_rank = *min_element(begin(ranks), end(ranks));

        ll r = (1LL)*cars * cars * min_rank;

        ll min_time=r;

        while (l <= r) {
            ll mid = l + (r - l) / 2;

            if (isPossible(ranks, cars, mid)) {
                min_time = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }

        return min_time;
    }
};