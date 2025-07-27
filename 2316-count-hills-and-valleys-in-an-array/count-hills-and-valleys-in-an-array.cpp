class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int cnt = 0;

        for (int j = 1; j < n - 1; j++) {
            if ((nums[i] < nums[j] && nums[j] > nums[j + 1]) ||
                (nums[i] > nums[j] && nums[j] < nums[j + 1])){
                    cnt++;
                    i=j;
                }
        }

        return cnt;
    }
};