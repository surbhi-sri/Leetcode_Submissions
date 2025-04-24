class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int xorr = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
            xorr ^= nums[i];

        int cnt = 0;
        for (int i = 0; i < 31; i++) {
            int xorrbit = ((xorr >> i) & 1) > 0;
            int kbit = ((k >> i) & 1) > 0;

            if (xorrbit != kbit)
                cnt++;
        }
        return cnt;
    }
};