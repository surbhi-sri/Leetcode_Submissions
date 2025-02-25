class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3)
            return n;
        int prev2 = 2;
        int prev = 3;
        for (int i = 4; i <= n; i++) {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};