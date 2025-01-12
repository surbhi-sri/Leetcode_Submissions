class Solution {
public:
    void fill(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        fill(nums, i + 1, temp, ans);
        temp.pop_back();
        fill(nums, i + 1, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        fill(nums, 0, temp, ans);
        return ans;
    }
};