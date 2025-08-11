class Solution {
public:
   
    const int mod=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;

        for (int i = 0; i < 32; i++) {
            if ((n & (1 << i)) != 0)
                powers.push_back(i);
        }

        int qn = queries.size();
        vector<int> ans(qn, 1);

        for (int i = 0; i < qn; i++) {
            int s = queries[i][0];
            int e = queries[i][1];
            unsigned long long val = 1;

            for (int j = s; j <= e; j++)
                val = (val * (1<<powers[j]))%mod;

            ans[i] = val;
        }

        return ans;
    }
};