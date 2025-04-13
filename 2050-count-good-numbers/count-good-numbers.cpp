class Solution {
public:
    const int m = 1e9 + 7;

    long long Findpower(long long a, long long b) {
        if (b == 0)
            return 1;

        long long half = Findpower(a, b / 2);
        long long res = (half * half) % m;

        if (b % 2 == 1)
            res = (res * a) % m;

        return res;
    }
    int countGoodNumbers(long long n) {
        return (long long)(Findpower(5, (n + 1) / 2) * Findpower(4, n / 2)) % m;
    }
};