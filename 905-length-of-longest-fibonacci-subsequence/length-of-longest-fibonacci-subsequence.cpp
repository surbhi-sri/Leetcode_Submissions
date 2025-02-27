class Solution {
public:
  
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        int len = 0;
        vector<vector<int>> dp(n, vector<int>(n, 2));

        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {

                int target = arr[k] - arr[j];

                if (mp.count(target) && mp[target] < j) {
                    int i = mp[target];
                    dp[j][k] = dp[i][j] + 1;
                }
                len = max(len, dp[j][k]);
            }
        }

        return len >= 3 ? len : 0;
    }
};