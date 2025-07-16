class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int odd = 0;
        int even = 0;
        int evenOdd = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                even++;
                if (i != 0 && nums[i - 1] % 2 == 1)
                    evenOdd++;
            } else {
                odd++;
                if (i != 0 && nums[i - 1] % 2 == 0)
                    evenOdd++;
            }
        }

        return max({even, odd, evenOdd});
    }
};