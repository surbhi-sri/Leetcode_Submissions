class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int findNextEvent(int low, int high, int end, vector<vector<int>>& events) {
        int ans = high + 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (events[mid][0] > end) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }

    int solve(vector<vector<int>>& events, int k, int idx) {
        if (idx >= n || k == 0)
            return 0;

        if (dp[idx][k] != -1)
            return dp[idx][k];

        int end = events[idx][1];
        int val = events[idx][2];

        int skip = solve(events, k, idx + 1);

        int j = findNextEvent(idx + 1, n - 1, end, events);

        int take = val + solve(events, k - 1, j);

        return dp[idx][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events), end(events));
        n = events.size();
        dp.resize(n + 1, vector<int>(k + 1, -1));
        return solve(events, k, 0);
    }
};