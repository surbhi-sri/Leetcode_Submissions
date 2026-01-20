class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                continue;
            int j;
            for (j = 0; j <= 31; j++) {
                if ((nums[i] & (1 << j)) == 0) {
                    ans[i] = nums[i] & ~(1 << (j - 1));
                    break;
                }
            }
        }
        return ans;
    }
};