class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<int> dp(n, 1), hash(n);
        int last_ind = 0;
        for (int i = 0; i < n; i++) {
            hash[i] = i;

            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
                if (dp[last_ind] < dp[i])
                    last_ind = i;
            }
        }

        vector<int> lds;
        lds.push_back(nums[last_ind]);

        while (hash[last_ind] != last_ind) {
            last_ind = hash[last_ind];
            lds.push_back(nums[last_ind]);
        }

        reverse(lds.begin(), lds.end());

        return lds;
    }
};