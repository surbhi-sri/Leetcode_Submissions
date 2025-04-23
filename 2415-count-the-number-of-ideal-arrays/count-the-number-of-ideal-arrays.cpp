class Solution {
public:
    int m = 1e9 + 7;

    void findsets(int m, vector<int>& cnt, vector<vector<int>>& dp) {
        if (dp[m][1] != 0)
            return;

        dp[m][1] = 1;
        cnt[1]++;

        for (int div = 2; div <= m; div++) {
            if (m % div == 0) {
                findsets(m / div, cnt, dp);

                for (int len = 1; len < 15; len++) {
                    if (dp[m / div][len] != 0) {
                        dp[m][len + 1] += dp[m / div][len];
                        cnt[len + 1] += dp[m / div][len];
                    }
                }
            }
        }
    }

    int findpower(long long n, long long p) {
        if (p == 0)
            return 1;

        long long half = findpower(n, p / 2);

        long long res = (half * half)%m;

        if (p % 2)
            res = (res * n)%m;

        return res;
    }

    long long modularnCr(int n, int r, vector<long long>& fact) {
        if (r < 0 || r > n)
            return 0;

        long long b = (fact[r] * fact[n - r]) % m;

        return (fact[n] * findpower(b, m - 2)) % m;
    }

    int idealArrays(int n, int maxValue) {
        vector<vector<int>> dp(maxValue + 1, vector<int>(15, 0));
        vector<int> cnt(15, 0);

        for (int i = 1; i <= maxValue; i++) {
            findsets(i, cnt, dp);
        }

        long long res = 0;
        vector<long long> fact(n + 1, 1);

        for (int i = 2; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % m;
        }

        for (int len = 1; len < 15; len++) {
            if (cnt[len] != 0) {
                long long possibilities = modularnCr(n - 1, len - 1, fact);

                res = (res + (cnt[len] * possibilities) % m) % m;
            }
        }
        return (int)res;
    }
};