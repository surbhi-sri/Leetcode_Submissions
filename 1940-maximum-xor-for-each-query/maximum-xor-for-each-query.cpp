class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int xorr = 0;

        for (int i = 0; i < n; i++)
            xorr ^= nums[i];

        vector<int> ans;
        int mx=pow(2, maximumBit)-1;

        for (int i = n - 1; i >= 0; i--) {
             int  k= mx^xorr;
             ans.push_back(k);
             xorr ^=nums[i];
        }

        return ans;
    }
};