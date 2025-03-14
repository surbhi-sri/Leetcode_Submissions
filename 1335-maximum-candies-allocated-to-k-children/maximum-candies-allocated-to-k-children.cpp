class Solution {
public:
    int mod = 1e9 + 7;

    int maximumCandies(vector<int>& candies, long long k) {

        int n = candies.size();

        int mx = 0;
        for (int i = 0; i < n; i++)
            mx = max(mx, candies[i]);

        int maxi = 0;
        int l = 1, r = mx;

        while (l <= r) {

            int mid = l + (r - l) / 2;
            long long cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += (candies[i] / mid) % mod;
            }

            if (cnt < k)
                r = mid - 1;
            else {
                maxi = mid;
                l = mid + 1;
            }
        }

        return maxi;
    }
};
