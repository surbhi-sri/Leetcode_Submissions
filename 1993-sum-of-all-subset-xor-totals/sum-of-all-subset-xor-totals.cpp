class Solution {
public:
    void solve(int i, int n, int xorr, vector<int>& nums, int& sum) {
        if (i >= n) {
            sum += xorr;
            return;
        }

         int xorr2=xorr;

        xorr ^= nums[i];
        solve(i + 1, n, xorr, nums, sum);

        solve(i + 1, n, xorr2, nums, sum);

        return;
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> temp;

        int xorr = 0, sum = 0;

        solve(0, n, xorr, nums, sum);

        return sum;
    }
};