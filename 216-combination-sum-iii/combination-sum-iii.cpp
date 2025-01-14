class Solution {
public:
    void add(vector<int>& num, int i, int k, int target, vector<int>& temp,
             vector<vector<int>>& ans) {
        if (target == 0 && temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        if (i >= num.size()) {
            if (target == 0 && temp.size() == k)
                ans.push_back(temp);
            return;
        }
        temp.push_back(num[i]);
        add(num, i + 1, k, target - num[i], temp, ans);
        temp.pop_back();
        add(num, i + 1, k, target, temp, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> num(9, 0);
        for (int i = 0; i < 9; i++)
            num[i] = i + 1;
        vector<int> temp;
        vector<vector<int>> ans;
        add(num, 0, k, n, temp, ans);
        return ans;
    }
};