class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;

        vector<int> temp;
        temp.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
        }

        n = temp.size();
        int cnt = 0;

        for (int i = 1; i < n - 1; i++) {
            if ((temp[i] > temp[i - 1] && temp[i] > temp[i + 1]) ||
                (temp[i] < temp[i - 1] && temp[i] < temp[i + 1]))
                cnt++;
        }

        return cnt;
    }
};