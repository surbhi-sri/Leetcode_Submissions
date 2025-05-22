class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> operation(n, 0);

        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            operation[l] += 1;
            if (r < n - 1)
                operation[r+1] -= 1;
        }

        for (int i = 0; i < n; i++) {
            if (i != 0)
                operation[i] = operation[i] + operation[i - 1];

            if (nums[i] > operation[i])
                return 0;
        }

        return 1;
    }
};