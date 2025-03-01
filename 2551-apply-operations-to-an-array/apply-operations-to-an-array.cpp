class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int l = 0, j = 0;

        while (j < n) {
            if (nums[l] == 0 && nums[j] == 0)
                j++;

            else {
                swap(nums[l], nums[j]);
                l++;
                j++;
            }
        }

        return nums;
    }
};