class Solution {
public:

    bool canJump(vector<int>& nums) {
        int n = nums.size();
         vector<int> dp(n, 0);
        dp[0]=1;

        for (int i = 1; i <n; i++) {
            for(int j=i-1; j>=0; j--){
                if(dp[j]==1 && j+nums[j]>=i){
                    dp[i]=1;
                     break;
                     }
            } 
        }
        
        return dp[n-1];
    }
};