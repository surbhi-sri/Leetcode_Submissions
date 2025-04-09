class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n=nums.size();

        int cnt=0;

        for(int i=0; i<n; i++){
            if(nums[i]<k) return -1;
            if(nums[i]==k) continue;

            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]++;
                cnt++;
            }
        }

        return cnt;
    }
};