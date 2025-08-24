class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int ans = 0, lastZeroIdx = -1;
        int n = nums.size();
        int i = 0;
        for(int j = i; j < n; j++){
            if(nums[j] == 0){
                i = lastZeroIdx + 1;
                lastZeroIdx = j;
            }

            ans = max(ans, j - i);
        }

        return ans;
    }
};