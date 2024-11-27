class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int n=nums.size();
      int sum=nums[0];
      for(int i=1;i<n;i++){
        if(nums[i-1]>0) nums[i]=nums[i]+nums[i-1];
        if(sum< nums[i]) sum=nums[i];
      }  
      return sum;
    }
};