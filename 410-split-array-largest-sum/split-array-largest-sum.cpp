class Solution {
public:
    int cnt_int(vector<int>& nums, int max_sum) {
        int cnt = 1, sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] <= max_sum) {
                sum += nums[i];
            } else {
                cnt++;
                sum = nums[i];
            }
        }
        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

         while(low<=high){
        int mid=(low+high)/2;
        if (cnt_int(nums, mid) <= k)
         high=mid-1;
        else low=mid+1;
       }
        return low;
    }
};