class Solution {
public:
    void count(vector<int>& candidates, int target, int i, vector<int>& temp,
               vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (j>i && candidates[j]==candidates[j-1]) continue;
            if(candidates[j]>target)  break;
                temp.push_back(candidates[j]);
                count(candidates, target - candidates[j], j + 1, temp, ans);
                temp.pop_back();
            
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        count(candidates, target, 0, temp, ans);
        return ans;
    }
};