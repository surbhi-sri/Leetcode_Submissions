class Solution {
public:
    int minBitFlips(int start, int goal) {
        if (start == goal)
            return 0;
        int cnt = 0;
        goal ^= start;
        while (goal != 0) {
            cnt += (goal & 1);
            goal = goal >> 1;
        }
        return cnt;
    }
};