class Solution {
public:
    int leftmostbit(int num) {
        int i = 0;
        while (num) {
            num = num >> 1;
            i++;
        }
        return i;
    }

    int rangeBitwiseAnd(int left, int right) {
        if (left == right)
            return left;

        if (left + 1 == right)
            return left & right;

        int leftmostbitofleft = leftmostbit(left);
        int leftmostbitofright = leftmostbit(right);

        if (leftmostbitofleft != leftmostbitofright)
            return 0;

        int ans = left;
        for (long long i = left + 1; i <= right; i++) 
        ans &=i;

        return ans;
    }
};