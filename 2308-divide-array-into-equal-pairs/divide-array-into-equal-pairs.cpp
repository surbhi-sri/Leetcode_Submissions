class Solution {
public:
    bool divideArray(vector<int>& nums) {

        unordered_map<int, int> mp;

        for(int i=0; i<nums.size(); i++) mp[nums[i]]++;

        for(auto m : mp) if(m.second%2) return 0;

        return 1;
    }
};