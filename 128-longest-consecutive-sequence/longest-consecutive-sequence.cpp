class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         int  n=nums.size();
         if(n==0) return 0;
        sort(nums.begin(), nums.end());

         unordered_map<int, int> mp;
         int mx=1;

         for(int i=0; i<n; i++){
            if(mp.find(nums[i]-1)!=mp.end()) mp[nums[i]]=mp[nums[i]-1]+1;
            else mp[nums[i]]=1;

            mx=max(mx, mp[nums[i]]);
         } 
         return mx;
    }
};