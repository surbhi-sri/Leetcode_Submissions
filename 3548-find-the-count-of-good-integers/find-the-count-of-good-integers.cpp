class Solution {
public:
    vector<long long> fact;

    Solution() {
        fact.resize(11, 1);
        for (int i = 1; i <= 10; i++)
            fact[i] = fact[i - 1] * i;
    }

    long long countGoodIntegers(int n, int k) {
        if (n == 1)
            return 9 / k;

        int halflen = (n + 1) / 2;
        long long l = pow(10, halflen - 1);
        long long r = pow(10, halflen) - 1;

        unordered_set<string> st;

        long long cnt = 0;
        for (long long i = l; i <= r; i++) {

            string half = to_string(i);
            string full = half;

            for (int j = n % 2 == 0 ? halflen - 1 : halflen - 2; j >= 0; j--)
                full += half[j];

            long long num = stoll(full);

            if (num % k != 0)
                continue;

            string str = full;
            sort(str.begin(), str.end());

            if (st.find(str) == st.end()) {
                st.insert(str);

                vector<int> count(10, 0);

                for (char& ch : str)
                    count[ch - '0']++;

                int total_digit = str.size();
                int total_zero = count[0];
                int total_nonZero = total_digit - total_zero;

                long long prem = total_nonZero * fact[total_digit - 1];

                for (int i = 0; i < 10; i++)
                    prem /= fact[count[i]];

                cnt += prem;
            }
        }
        return cnt;
    }
};