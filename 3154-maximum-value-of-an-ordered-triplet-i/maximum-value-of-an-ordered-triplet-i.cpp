class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<long long> left_max(n, 0), right_max(n, 0);

        for (int i = 1; i < n; i++) {
            left_max[i] = max(left_max[i - 1], (long long)nums[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], (long long)nums[i + 1]);
        }

        long long res = 0;

        for (int i = 1; i < n; i++)
            res = max(res, (left_max[i] - nums[i]) * right_max[i]);

        return res;
    }
};