#define ll long long int
#define vi vector<ll>
#define vvi vector<vi>
class Solution {
public:
    const ll MOD = 1e9 + 7;
    ll help(int idx, int cnt, int k, vector<int>& freq, vvi& dp) {
        if (idx >= freq.size()) {
            // If we've processed all frequencies, check if cnt < k (invalid)
            if (cnt < k)
                return 1;
            else
                return 0;
        }

        if (dp[idx][cnt] != -1)
            return dp[idx][cnt]; // Memoization

        ll ans = 0;

        for (ll take = 1; take <= freq[idx]; ++take) {
            if (take + cnt < k) {
                ans = (ans + help(idx + 1, take + cnt, k, freq, dp)) % MOD;
            } else
                break; // No need to proceed further
        }

        return dp[idx][cnt] = ans % MOD;
    }
    
    int possibleStringCount(string word, int k) {
       int n = word.size();

        if (n < k)
            return 0; // Edge case: original string can't have >=k distinct chars

        vector<int> freq;
        int cnt = 1;
        // Run-Length Encoding (RLE)
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1])
                ++cnt;
            else {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt); // Add the last run

        ll totalPoss = 1ll;
        for (ll x : freq) {
            totalPoss = (totalPoss * x) % MOD; // Total possible original strings
        }

        if (freq.size() >= k)
            return totalPoss; // All are valid since original has >=k distinct chars

        int t = freq.size();
        vvi dp(t + 1, vi(k + 1, 0)); // DP table

        // Base Case: If all frequencies are processed, cnt < k → 1 (invalid)
        for (int kk = 0; kk < k; ++kk)
            dp[t][kk] = 1;

        for (int idx = t - 1; idx >= 0; --idx) {
            vector<ll> prefix(k + 2, 0); // Prefix sum for optimization

            for (int i = 1; i <= k; ++i) {
                prefix[i] = prefix[i - 1] + dp[idx + 1][i - 1];
            }

            for (int cnt = k - 1; cnt >= 0; --cnt) {
                ll ans = 0;

                // Using prefix sums to avoid recalculating
                ans = (ans + prefix[min(cnt + freq[idx], k-1) + 1] - prefix[cnt+1]) % MOD;

                dp[idx][cnt] = ans % MOD;
            }
        }

        // Subtract invalid cases from total possibilities
        return (totalPoss - dp[0][0] + MOD) % MOD;  
    }
};