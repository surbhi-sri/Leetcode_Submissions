class Solution {
public:
    void permutate(vector<int> &nums, vector<int> freq, vector<int> &temp,
                   vector<vector<int>> &ans) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                freq[i] = 1;
                temp.push_back(nums[i]);
                permutate(nums, freq, temp, ans);
                freq[i] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> freq(nums.size(), 0);
        permutate(nums, freq, temp, ans);
        return ans;
    }
};