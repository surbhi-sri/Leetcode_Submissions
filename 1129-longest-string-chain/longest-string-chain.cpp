class Solution {
public:
    bool check(string &s1, string &s2) {
        if (s1.size() != s2.size() + 1)
            return 0;

        int i = 0, j = 0;

        while (i < s1.size()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else
                i++;
        }

        if (i == s1.size() && j == s2.size())
            return 1;
        else
            return 0;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {

            for (int prev = 0; prev < i; prev++) {

                if (check(words[i], words[prev]) && dp[prev] + 1 > dp[i]) {

                    dp[i] = dp[prev] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};