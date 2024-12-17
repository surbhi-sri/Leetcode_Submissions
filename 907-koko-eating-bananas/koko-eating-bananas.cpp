class Solution {
public:
    int calculate_time(vector<int>& piles, int bananas, int n, int h) {
        int totalH = 0;
        for (int i = 0; i < n; i++) {
            totalH += ceil((double)piles[i] / (double)bananas);
            if (totalH > h)
                return h + 1;
        }
        return totalH;
    }

    int find_max(vector<int>& piles, int n) {
        int mx = INT_MIN;
        for (int i = 0; i < n; i++)
            mx = max(piles[i], mx);
        return mx;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max_value = find_max(piles, n);
        int k = max_value;
        int low = 1, high = max_value;
        while (low <= high) {
            int mid = (low + high) / 2;
            int time = calculate_time(piles, mid, n, h);
            if (time <= h) {
                k = min(mid, k);
                high = mid - 1;
            } else
                low = mid + 1;
        }

         return k;
    }
};
