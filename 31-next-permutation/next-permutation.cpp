class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        while (n > 0 && nums[n - 1] >= nums[n])
            n--;
        if (n == 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        int ind = n - 1, mn = 200, mni;
        for (int i = n; i < nums.size(); i++) {
            if (nums[i] > nums[ind] && nums[i] < mn) {
                mn = nums[i];
                mni = i;
            }
        }
        swap(nums[ind], nums[mni]);
        sort(nums.begin()+ind+1, nums.end());
        return;
    }
};