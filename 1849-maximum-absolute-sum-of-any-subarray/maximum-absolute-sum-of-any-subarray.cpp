class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0;
        int mx=INT_MIN;

        int n=nums.size();

        for(int i=0; i<n; i++){
            sum +=nums[i];

            mx= max(mx, sum);

            if(sum<0) sum=0;
        }
       
       sum=0;
        for(int i=0; i<n; i++){
            sum -=nums[i];

            mx= max(mx, sum);

            if(sum<0) sum=0;
        }

        return mx;
    }
};