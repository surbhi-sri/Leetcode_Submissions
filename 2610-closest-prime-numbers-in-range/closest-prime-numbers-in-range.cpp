class Solution {
public:
    vector<bool> Sieve_of_Eratosthenes(int right) {
        vector<bool> prime(right + 1, 1);
        prime[0] = 0;
        prime[1] = 0;

        for (int i = 2; i*i <= right; i++) {
            if (prime[i] == 1) {
                for (int j = i * i; j <= right; j += i) {
                    prime[j] = 0;
                }
            }
        }
        return prime;
    }

    vector<int> closestPrimes(int left, int right) {

        if (right <= 2)
            return {-1, -1};
        vector<bool> isPrime = Sieve_of_Eratosthenes(right);

        vector<int> prime;

        for (int i = left; i <= right; i++) {
            if (isPrime[i]==1)
                prime.push_back(i);
        }

        int mn = 100000000;
        vector<int> res={-1, -1};

        for (int i = 1; i < prime.size(); i++) {
            if (prime[i] - prime[i-1] < mn) {
                mn = prime[i] - prime[i-1];
                res = {prime[i-1] , prime[i]};
            }
        }

        return res;
    }
};