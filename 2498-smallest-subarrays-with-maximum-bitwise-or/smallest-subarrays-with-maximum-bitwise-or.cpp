class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n);
        vector<int> setBit(32, -1);

        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            int end = i;
            for (int j = 0; j < 32; j++) {
                if ((num & (1 << j)) ==0) {
                    if (setBit[j] != -1)
                        end = max(end, setBit[j]);
                } else
                    setBit[j] = i;
            }

            res[i]=end-i+1;
        }

        return res;
    }
};