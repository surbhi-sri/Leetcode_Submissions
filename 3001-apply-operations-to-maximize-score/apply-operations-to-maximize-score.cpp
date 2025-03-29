class Solution {
public:
    const int mod = 1e9 + 7;

    vector<int> primes;
    unordered_map<int, int> primeFactorCache;

    void seive(int n) {
        vector<int> isPrime(n + 1, 1);

        isPrime[0] = isPrime[1] = 0;

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (long long j = 1LL * i * i; j <= n; j += i)
                    isPrime[j] = 0;
            }
        }
    }

    int primeScore(int x) {
        if (x < 2)
            return 0;

        if (primeFactorCache.find(x) != primeFactorCache.end())
            return primeFactorCache[x];

        int cnt = 0, num = x;
        for (int prime : primes) {
            if (x % prime == 0) {
                cnt++;
                while (x % prime == 0)
                    x /= prime;
                if (x == 1)
                    break;
            }
        }
        if (x > 1)
            cnt++;
        return primeFactorCache[num] = cnt;
    }

    long long pows(int a, int b) {
        long long res = 1, base = a;
        while (b > 0) {
            if (b % 2 == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            b /= 2;
        }
        return res;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int mx_ele = *max_element(nums.begin(), nums.end());

        seive(mx_ele);

        vector<int> prime_score(n);

        for (int i = 0; i < n; i++) {
            prime_score[i] = primeScore(nums[i]);
        }

        stack<int> st;
        vector<int> nge(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && prime_score[st.top()] <= prime_score[i])
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // vector<long long> total_sub(n);
        // stack<int> st2;

        // for (int i = 0; i < n; i++) {
        //     while (!st2.empty() && prime_score[st2.top()] < prime_score[i])
        //         st2.pop();
        //     int npe = st2.empty() ? -1 : st2.top();
        //     st2.push(i);

        //     total_sub[i] = (1LL *(nge[i] - i) * (i - npe))%mod;
        // }
        vector<long long> total_sub(n);
        stack<int> st2;

        for (int i = 0; i < n; i++) {
            while (!st2.empty() && prime_score[st2.top()] < prime_score[i])
                st2.pop();
            int npe = st2.empty() ? -1 : st2.top();
            st2.push(i);

            // ✅ Prevent overflow by converting everything to long long
            total_sub[i] = (1LL * (nge[i] - i)) * (1LL * (i - npe));
        }

        priority_queue<pair<int, long long>> pq;

        for (int i = 0; i < n; i++)
            pq.push({nums[i], total_sub[i]});

        long long mx_score = 1;

        while (!pq.empty()) {
            int num = pq.top().first;
            long long sub = pq.top().second;
            pq.pop();

            if (k >= sub) {
                long long power = pows(num, sub);
                mx_score = (mx_score * power) % mod;
                k -= sub;
            } else {
                long long power = pows(num, k);
                mx_score = (mx_score * power) % mod;
                break;
            }
        }

        return mx_score;
    }
};