class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {

        int t = 1;
        while (1) {
            long long val = (long long)num1 - (long long)t * num2;
            if (val < 0)
                return -1;

             long long bit_cnt = __builtin_popcountll(val);
            if (bit_cnt <= t && t <= val)
                return t;
            t++;
        }

        return -1;
    }
};