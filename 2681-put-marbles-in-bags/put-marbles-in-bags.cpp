class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {

        int n = weights.size();

        if (k == 1 || k == n)
            return 0;

        n--;
        vector<int> pairs(n);

        for (int i = 0; i < n; i++)
            pairs[i] = weights[i] + weights[i + 1];

        sort(begin(pairs), end(pairs));

        long long mn = 0, mx = 0;
        for (int i = 0; i < k - 1; i++) {
            mn = (mn + pairs[i]);
            mx = (mx + pairs[n - 1 - i]);
        }

        return (mx - mn);
    }
};