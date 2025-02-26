class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        if (n == 1)
            return nums[0];

        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n - 1; i++) {

            int max_sum = max(nums[i] + prev2, prev);

            prev2 = prev;
            prev = max_sum;
        }

        int prevN = nums[1];
        int prev2N = 0;
        for (int i = 2; i < n ; i++) {

            int max_sum = max(nums[i] + prev2N, prevN);

            prev2N = prevN;
            prevN = max_sum;
        }

        return max(prev, prevN);
    }
};