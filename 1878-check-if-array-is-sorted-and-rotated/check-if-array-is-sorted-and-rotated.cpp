class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return 1;
        int i;
        for (i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i])
                break;
        }
        vector<int> nums2;
        int n2 = i;
        while (i < n) {
            nums2.push_back(nums[i]);
            i++;
        }
        int j = 0;
        while (j < n2) {
            nums2.push_back(nums[j]);
            j++;
        }
        for (i = 1; i < n; i++) {
            if (nums2[i - 1] > nums2[i])
                return 0;
        }
        return 1;
    }
};