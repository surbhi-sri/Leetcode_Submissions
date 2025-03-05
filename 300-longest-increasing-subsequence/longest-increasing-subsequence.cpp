class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (seq.empty() || seq.back() < nums[i])
                seq.push_back(nums[i]);
            else {
                int index =
                    lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                seq[index] = nums[i];
            }
        }

        return seq.size();
    }
};