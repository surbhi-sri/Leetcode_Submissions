class Solution {
public:
    long long coloredCells(int n) {
        if (n == 1)
            return n;

        long long p1 = pow(n, 2);
        long long p2 = pow(n - 1, 2);

        return (p1+p2);
    }
};