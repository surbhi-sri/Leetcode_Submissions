class Solution {
public:
    int sum_division(vector<int>& nums, int div, int n, int threshold) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)nums[i] /(double) div);
            if (sum >threshold)
                return threshold+1;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1, high = INT_MIN;
        for (int i = 0; i < n; i++) {
            high = max(high, nums[i]);
        }
        int ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            int sum = sum_division(nums, mid, n, threshold);
            if (sum <= threshold) {
                ans = min(ans, mid);
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }
};