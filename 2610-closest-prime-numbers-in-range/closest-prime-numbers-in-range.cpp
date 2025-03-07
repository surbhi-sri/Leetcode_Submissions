class Solution {
public:
    bool isPrime(int x) {

        if (x <= 1)
            return 0;

        if (x == 2 || x == 3)
            return 1;

        if (x % 2 == 0 || x % 3 == 0)
            return 0;

        for (int i = 5; i * i <= x; i += 6) {
            if (x % i == 0 || x % (i + 2) == 0)
                return 0;
        }
        return 1;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> v;

    
        int k = 0;

        int s, mn = 1000000;

        for (int i = left; i <= right; i++) {

            if (isPrime(i)) {
                v.push_back(i);
                k++;

                if (v.size() >= 2) {
                    if (mn > v[k - 1] - v[k-2]) {
                        mn = v[k - 1] - v[k-2];
                        s = k-2;
                    }
                }
            }
        }

        //  for(int i=0; i<k; i++) cout<<v[i]<<" "<<v[i+1]<<endl;
    cout<<endl;
        if (mn == 1000000)
            return {-1, -1};
        else
            return {v[s], v[s + 1]};
    }
};