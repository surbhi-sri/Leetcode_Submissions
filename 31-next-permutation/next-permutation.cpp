class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        while (n > 0 && nums[n - 1] >= nums[n])
            n--;
        if (n == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int ind = n - 1;
        for (int i = nums.size()-1; i >= ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[ind], nums[i]);
                break;
            }
        }

        reverse(nums.begin() + ind + 1, nums.end());
        return;
    }
};