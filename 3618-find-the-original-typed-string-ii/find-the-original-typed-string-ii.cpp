class Solution {
public:
    int m = 1e9 + 7;

    int possibleStringCount(string word, int k) {
        vector<int> freq;
        int cnt = 1;
        int n = word.size();

        if (n < k)
            return 0;

        for (int i = 1; i < n; i++) {
            if (word[i] != word[i - 1]) {
                freq.push_back(cnt);
                cnt = 1;
            } else
                cnt++;
        }
        freq.push_back(cnt);

        long long totalPossible = 1;

        for (int& f : freq)
            totalPossible = (totalPossible * f) % m;

        if (freq.size() >= k)
            return totalPossible;

        n = freq.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int cnt = 0; cnt < k; cnt++)
            dp[n][cnt] = 1;

        for (int i = n - 1; i >= 0; i--) {

            vector<int> prefix(k + 1, 0);
            for (int h = 1; h <= k; h++) {
                prefix[h] = (prefix[h - 1] + dp[i + 1][h - 1]) % m;
            }

            for (int cnt = k - 1; cnt >= 0; cnt--) {
                int l = cnt + 1;
                int r = cnt + freq[i];

                if (r + 1 > k)
                    r = k - 1;

                if (l <= r)
                    dp[i][cnt] = (prefix[r + 1] - prefix[l] + m) % m;
            }
        }

        return (totalPossible - dp[0][0] + m) % m;
    }
};