class Solution {
public:

int minSum(vector<int>& nums){
    int mn=INT_MAX;
    int ind=-1;
    int n=nums.size();
    for(int i=0; i<n-1; i++){
        if(mn> nums[i]+nums[i+1]){
            mn=nums[i]+nums[i+1];
            ind=i;
        }
    }
    return ind;
}

    int minimumPairRemoval(vector<int>& nums) {
        int op=0;
        while(!is_sorted(begin(nums), end(nums))){
            int ind=minSum(nums);
            nums[ind]=nums[ind]+nums[ind+1];
            nums.erase(nums.begin()+ind+1);
            op++;
        }

        return op;
    }
};