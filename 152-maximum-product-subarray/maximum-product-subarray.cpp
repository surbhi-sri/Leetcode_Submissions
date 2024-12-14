class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long p = 1, max_p = INT_MIN;
        for (int i = 0; i < n; i++) {
            p *= nums[i];
            max_p = max(p, max_p);
            if (p == 0)
                p = 1;
        }

        p = 1;
        for (int i = n - 1; i >= 0; i--) {
            p *= nums[i];
            max_p = max(p, max_p);
            if (p == 0)
                p = 1;
        }
        return max_p;
    }
};