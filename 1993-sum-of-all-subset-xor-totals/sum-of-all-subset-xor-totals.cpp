class Solution {
public:
    void solve(int i, int n, vector<int>& temp, vector<int>& nums,
               vector<vector<int>>& ans) {
        if (i >= n) {
            if (temp.size() >= 1)
                ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i + 1, n, temp, nums, ans);

        temp.pop_back();
        solve(i + 1, n, temp, nums, ans);

        return;
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, n, temp, nums, ans);

        int sum = 0;
        n = ans.size();

        for (int i = 0; i < n; i++) {

            int xorr = 0;
            for (int j = 0; j < ans[i].size(); j++) {
                xorr ^= ans[i][j];
            }
            sum += xorr;
        }

        return sum;
    }
};