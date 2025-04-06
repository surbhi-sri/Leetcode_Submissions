class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<int> last_ind(n, -1);
        vector<int> dp(n, 1);

        int last_chosen = 0;
        int maxL = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {

                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        last_ind[i] = j;
                    }

                    if (dp[i] > maxL){
                        maxL = dp[i];
                   last_chosen=i;
                   }     
                }
            }
        }

        vector<int> ans;

        while(last_chosen!=-1){
            ans.push_back(nums[last_chosen]);
            last_chosen=last_ind[last_chosen];
        }

        return ans;
    }
};