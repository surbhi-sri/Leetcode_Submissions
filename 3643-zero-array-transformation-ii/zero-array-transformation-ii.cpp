class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        int qn = queries.size();
        int sum = 0;
        int k = 0;
        vector<int> diffArray(n + 1);

        for (int i = 0; i < n; i++) {
            while (sum + diffArray[i] < nums[i]) {
                k++;
                if (k > qn)
                    return - 1;

                int l = queries[k - 1][0];
                int r = queries[k - 1][1];
                int val = queries[k - 1][2];

                if (r >= i) {
                    diffArray[max(i, l)] += val;
                    diffArray[r + 1] -= val;
                }

            }
            sum+=diffArray[i];
        }

        return k;
    }
};
