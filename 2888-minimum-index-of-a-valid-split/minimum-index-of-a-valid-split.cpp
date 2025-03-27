class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominant = -1;
        int cnt = 0;

        for (int num : nums) {
            if (cnt == 0) {
                dominant = num;
                cnt = 1;
            } else if (dominant == num)
                cnt++;
            else
                cnt--;
        }

        cnt = 0;

        for (int num : nums) {
            if (num == dominant)
                cnt++;
        }

        int curr_cnt = 0;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == dominant)
                curr_cnt++;
            if (curr_cnt > (i + 1) / 2 && (cnt - curr_cnt) > (n - i - 1) / 2)
                return i;
        }

        return -1;
    }
};