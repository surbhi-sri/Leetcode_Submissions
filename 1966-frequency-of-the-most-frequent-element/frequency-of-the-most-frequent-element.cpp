class Solution {
public:
    int bSearch(int target_ind, int k, vector<int>& nums,
                vector<long>& pre_sum) {
        int l = 0;
        int r = target_ind;
        int target = nums[target_ind];
        int best_ind = target_ind;

        while (l <= r) {
            int mid = r - (r - l) / 2;
            long count = target_ind - mid + 1;
            long window_sum = count * target;
            long our_sum = pre_sum[target_ind] - pre_sum[mid] + nums[mid];
            int operation = window_sum - our_sum;
            if (operation > k)
                l = mid + 1;
            else {
                best_ind = mid;
                r = mid - 1;
            }
        }
        return target_ind - best_ind + 1;
    }

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long> pre_sum(n,0);
        pre_sum[0] = nums[0];

        for (int i = 1; i < n; i++)
            pre_sum[i] = pre_sum[i - 1] + nums[i];

        int res = 0;
        for (int target_ind = 0; target_ind < n; target_ind++)
            res = max(res, bSearch(target_ind, k, nums, pre_sum));

        return res;
    }
};