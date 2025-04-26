class Solution {
public:
    long long minEnd(int n, int x) {
        if (n == 1)
            return x;

        long long ans = x;

        for (int i = 1; i < n; i++) {
            ans += 1;
            ans |= x;
        }
        return ans;
    }
};