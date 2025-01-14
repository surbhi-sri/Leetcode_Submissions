class Solution {
public:
    void count(vector<int>& candidates, int target, int i, vector<int>& temp,
               vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (0 > target)
            return;

        if (i >= candidates.size()) {
            if (target == 0)
                ans.push_back(temp);
            return;
        }

        temp.push_back(candidates[i]);
        count(candidates, target - candidates[i], i, temp, ans);
        temp.pop_back();
        count(candidates, target, i + 1, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        count(candidates, target, 0, temp, ans);
        return ans;
    }
};