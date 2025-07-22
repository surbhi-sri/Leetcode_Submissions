class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int max_sum = 0;
        int sum = 0;
        int i = 0, j = 0;
        int n = nums.size();

        while (j < n) {
            sum += nums[j];

            while (mp[nums[j]] != 0) {
                sum -= nums[i];
                mp[nums[i]]--;
                i++;
            }

            mp[nums[j]]++;
            max_sum = max(max_sum, sum);
            j++;
        }

        return max_sum;
    }
};