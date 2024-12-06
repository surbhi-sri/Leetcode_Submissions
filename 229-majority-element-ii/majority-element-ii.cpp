class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     int n=nums.size();
     int d=n/3;
     map<int, int> mp;
     vector<int> ans;
     for(int i=0;i<n;i++) mp[nums[i]]++;
     for(auto x: mp) if(x.second >d) ans.push_back(x.first);
     return ans;
    }
};