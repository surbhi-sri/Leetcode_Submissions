class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        long long res = 0;
        long long max_diff = 0;
        long long maxi = 0;

        for (int i = 0; i < n; i++) {
            res = max(res, max_diff * nums[i]);
            max_diff = max(max_diff, (maxi - nums[i]));
            maxi = max(maxi, (long long)nums[i]);
        }

        return res;
    }
};