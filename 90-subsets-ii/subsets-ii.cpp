class Solution {
public:
    void count(vector<int>& nums, int i, vector<int>& temp,
               vector<vector<int>>& ans) {

        ans.push_back(temp);

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1])
                continue;
            temp.push_back(nums[j]);
            count(nums, j + 1, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        count(nums, 0, temp, ans);
        return ans;
    }
};