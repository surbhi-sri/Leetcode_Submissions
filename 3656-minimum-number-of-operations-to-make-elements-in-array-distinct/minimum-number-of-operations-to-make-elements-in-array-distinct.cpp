class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> vis(101, 0);

        int n = nums.size() - 1;
        while (n >= 0) {
            if (vis[nums[n]] > 0)
                break;
            vis[nums[n]]++;
            n--;
        }

        if (n < 0)
            return 0;

        int operation = 0;

        if ((n + 1) % 3 != 0)
            operation++;

        operation += ((n + 1) / 3);

        return operation;
    }
};