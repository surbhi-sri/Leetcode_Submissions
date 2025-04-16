class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long l = 0, r = 0;
        long long pairs = 0, ans = 0;

        int n = nums.size();
        unordered_map<int, int> mp;

        while (l <= r && r < n) {
            pairs += mp[nums[r]];
            mp[nums[r]]++;

            while (pairs >= k) {
                ans += (n - r);

                mp[nums[l]]--;
                pairs -= mp[nums[l]];

                l++;
            }

            r++;
        }

        return ans;
    }
};