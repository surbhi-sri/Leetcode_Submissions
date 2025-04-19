class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long cnt = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++) {
            int num = nums[i];
            long long idx_lower =
                lower_bound(nums.begin() + i + 1, nums.end(), lower - num) -
                (nums.begin() + i + 1);

            long long idx_upper =
                upper_bound(nums.begin() + i + 1, nums.end(), upper - num) -
                (nums.begin() + i + 1);

            cnt += (idx_upper - idx_lower);
        }

        return cnt;
    }
};