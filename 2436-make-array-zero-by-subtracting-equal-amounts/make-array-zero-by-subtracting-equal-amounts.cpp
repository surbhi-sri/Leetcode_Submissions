class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int op = 0, amt = 0;

        for (int& num : nums) {
            if (num == 0)
                continue;
            if (amt != num) {
                op++;
                amt = num;
            }
        }
        return op;
    }
};