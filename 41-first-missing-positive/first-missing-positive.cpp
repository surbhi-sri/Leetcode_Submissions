class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int notfound = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                notfound = 0;
            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        }

        if (notfound)
            return 1;

        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            num--;
            if (nums[num] > 0)
                nums[num] *= -1;
        }

        for (int i = 1; i < n; i++)
            if (nums[i] > 0)
                return i + 1;

        return n + 1;
    }
};