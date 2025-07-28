class Solution {
public:
    void solve(vector<int>& nums, int i, int orr, int& cnt, int& max_orr) {
        if (i == nums.size()) {
            if (orr > max_orr) {
                max_orr = orr;
                cnt = 1;
            } else if (orr == max_orr)
                cnt++;

            return;
        }

        solve(nums, i + 1, orr, cnt, max_orr);;
        solve(nums, i + 1, (orr|nums[i]), cnt, max_orr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int max_orr = 0;
        int cnt = 0;

        solve(nums, 0, 0, cnt, max_orr);

        return cnt;
    }
};