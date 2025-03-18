class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
     int sum=0;
     int xorr=0;
     int j=0;
     int max_len=0;

     for(int i=0; i<n; i++){
     sum+=nums[i];
     xorr ^=nums[i];

     while(sum!=xorr && j<=i &&j<n){
        sum -=nums[j];
        xorr ^=nums[j];
        j++;
     }
    max_len= max(max_len, i-j+1);
     }      


      return max_len;
    }
};