class Solution {
public:
    vector<int> min_max(vector<int>& bloomDay, int n) {
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            mn = min(mn, bloomDay[i]);
            mx = max(mx, bloomDay[i]);
        }
        return {mn, mx};
    }

    int n_bouquets(vector<int>& bloomDay, int n, int days, int k) {
        int cnt = 0, bouquets = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= days) {
                cnt++;
                if (cnt == k) {
                    bouquets++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
       long long  no_of_fl=m * 1ll * k * 1ll;
        if (n < no_of_fl)
            return -1;
        vector<int> mn_mx = min_max(bloomDay, n);

        int ans = mn_mx[1];

        int low = mn_mx[0], high = mn_mx[1];

        while (low <= high) {
            int mid = (low + high) / 2;
            int bouquets = n_bouquets(bloomDay, n, mid, k);
            if (bouquets >= m) {
                ans = min(mid, ans);
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }
};