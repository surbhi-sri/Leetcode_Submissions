class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int streak = 0;
        int zero = -1;
        for (int& num : nums) {
            if (num == 1)
                streak++;
            else {
                if (zero != -1)
                    ans = max(ans, streak + zero);
                zero = streak;
                streak = 0;
            }
        }
        if (zero != -1)
            ans = max(ans, streak + zero);
        else
            ans = streak - 1;

        return ans;
    }
};