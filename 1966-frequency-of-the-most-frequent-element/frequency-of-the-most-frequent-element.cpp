class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0;
        long curr = 0;

        for (int right = 0; right < n; right++) {
            long target = nums[right];
            curr += target;

            if ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }
        }
        return n-left;
    }
};