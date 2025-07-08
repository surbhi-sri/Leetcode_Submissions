class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<vector<int>>& events, int k, int idx) {
        if (idx >= n || k == 0)
            return 0;

        if (dp[idx][k] != -1)
            return dp[idx][k];

        int start = events[idx][0];
        int end = events[idx][1];
        int val = events[idx][2];

        int skip = solve(events, k, idx + 1);

        int j = idx + 1;
        for (; j < n; j++) {
            if (events[j][0] > end)
                break;
        }

        // using binary search with the help of upper bound
        // vector<int> temp = {end, INT_MAX, INT_MAX};
        // int j = upper_bound(events.begin() + idx + 1, events.end(), temp) -
        //         events.begin();

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