class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int len = 0;

        sort(nums.begin(), nums.end());

        int ele1 = nums[0];
        int cnt1 = 0;
        int j = 0;

        while (j < n && nums[j] == ele1) {
            j++;
            cnt1++;
        }

        while (j < n) {
            int ele2 = nums[j];
            int cnt2 = 0;

            while (j < n && nums[j] == ele2) {
                j++;
                cnt2++;
            }

            if (ele1 == ele2 - 1) {
                len = max(len, cnt1 + cnt2);
            }
            ele1 = ele2;
            cnt1 = cnt2;
        }

        return len;
    }
};