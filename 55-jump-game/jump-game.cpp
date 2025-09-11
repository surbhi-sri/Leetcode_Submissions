class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = nums[0];

        int i, n = nums.size();

        for (i = 0; i < n; i++) {
            if (i > maxJump)
                return 0;
            maxJump = max(maxJump, i + nums[i]);
        }
        return 1;
    }
};