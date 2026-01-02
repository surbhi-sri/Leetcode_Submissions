class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
       int n=nums.size();
       int repeat=n/2;

       for(int i=0; i<n/2+1; i++){
          if(nums[i]==nums[i+repeat-1]) return nums[i];
       }
      return 0;
    }
};