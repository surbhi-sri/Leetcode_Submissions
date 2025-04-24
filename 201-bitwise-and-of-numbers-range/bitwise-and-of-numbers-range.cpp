class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {


        if(left==right) return left;

        for (int i = 1; i < 31; i++) {
            left = left >> 1;
            right = right >> 1;

            if (left == right) {
                return (left << (i));
            }
        }

        return 0;
    }
};