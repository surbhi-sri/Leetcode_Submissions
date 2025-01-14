class Solution {
public:
    void count(vector<int>& nums, int j, vector<int>& temp,
               set<vector<int>>& ans) {
        if (j >= nums.size()) {
            ans.insert(temp);
            return;
        }

        temp.push_back(nums[j]);
        count(nums, j + 1, temp, ans);
        temp.pop_back();
        count(nums, j + 1, temp, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> temp;
        count(nums, 0, temp, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};