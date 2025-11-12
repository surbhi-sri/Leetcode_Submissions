class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for (int num : nums) {
            if (num == 1)
                cnt++;
        }

        if (cnt > 0)
            return n - cnt;

        int op = n+1;

        for (int i = 0; i < n; i++) {
            int gcd = nums[i];
            for (int j = i + 1; j < n; j++) {
                gcd = __gcd(gcd, nums[j]);
                if (gcd == 1)
                    op = min(op, j - i);
            }
        }

        if(op==n+1) return -1;

        return op + n - 1;
    }
};