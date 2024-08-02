class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
            if (nums[i] == 1)
                cnt++;

        if (cnt == n || cnt == n - 1 || cnt == 0)
            return 0;

        int curr = 0, temp = 0, j = 1, i;
        for (i = 0; i < cnt; i++)
            if (nums[i] == 1)
                temp++;

        while (j < n) {
            curr = max(temp, curr);
            if (nums[j - 1] == 1)
                temp--;
            if (nums[i] == 1)
                temp++;
            j++;
            i++;
            if (i >= n)
                i %= n;
        }
        curr = max(temp, curr);

        return cnt - curr;
    }
};