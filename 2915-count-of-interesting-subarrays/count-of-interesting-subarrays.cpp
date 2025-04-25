class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        long long res = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;

        for (int x : nums) {
            if (x % m == k)
                cnt++;

            int rem1 = cnt % m;
            int rem2 = (rem1 - k + m) % m;
            res+=mp[rem2];
            mp[rem1]++;
        }
        return res;
    }
};