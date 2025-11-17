class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if(nums[i]==1){
                if(prev<0) prev=i;
                else if(i-prev-1<k) return 0;
                prev=i;
            }
        }

        return 1;
    }
};