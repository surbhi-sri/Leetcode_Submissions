class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;

        for (i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1])
                break;
        }

        if (i == 0)
            reverse(nums.begin(), nums.end());
        else {
            sort(nums.begin() + i, nums.end());
            int num = nums[i - 1];
            for (int k=i; k < n; k++)
                if (nums[k] > num) {
                    swap(nums[i - 1], nums[k]);
                    break;
                }
        }
    }
};