class Solution {
public:
    bool solve(int n, int target, vector<int> nums) {

        vector<bool> prev(target + 1, 0);

        prev[0] = 1;

        // if (target >= nums[0])
        //     prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {
            vector<bool> curr(target + 1, 0);
            curr[0] = 1;
            for (int j = 1; j <= target; j++) {

                bool notTake = prev[j];
                bool take = 0;
                if (j >= nums[i])
                    take = prev[j - nums[i]];

                curr[j] = take | notTake;
            }
            prev=curr;
        }

        return prev[target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int target = 0;
        for (int i = 0; i < n; i++)
            target += nums[i];

        if (target % 2)
            return 0;

        target /= 2;

        return solve(n, target, nums);
    }
};