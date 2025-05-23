class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        ll sum = 0;
        vector<int> fayda;

        for (ll num : nums) {
            sum += num;

            fayda.push_back((num ^ k) - num);
        }

        sort(fayda.rbegin(), fayda.rend());

        int n = fayda.size();

        for (int i = 0; i < n - 1; i += 2) {
            int inc_sum = fayda[i] + fayda[i + 1];
            if (inc_sum > 0)
                sum += inc_sum;
        }

        return sum;
    }
};