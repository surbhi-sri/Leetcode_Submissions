class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n, 0);
        int temp = 0;

        for (int i = 0; i < n; i++) {
            temp = (temp * 2 + nums[i])%5;

            ans[i] = temp == 0;
        }
        return ans;
    }
};