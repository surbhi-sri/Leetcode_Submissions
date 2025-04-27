class Solution {
public:
    void updateWindow(int num, vector<int>& bits , int val) {
        for (int i = 0; i < 32; i++) {
            if ((num & (1 << i)) > 0)
                bits[i]+=val;
        }
    }

    int getDecimal(vector<int>& bits){
        int num=0;
       
        for (int i = 0; i < 32; i++){
            if(bits[i]>0)
            num= num|(1<<i);
        }

        return num;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0;
        int len = INT_MAX;

        vector<int> bits(32, 0);

        while (j < n) {
            updateWindow(nums[j], bits, 1);  //adding number

            while (i <= j && getDecimal(bits) >= k) {
                len = min(len, j - i + 1);
                updateWindow(nums[i], bits, -1); //removing number
                i++;
            }

            j++;
        }

        return len == INT_MAX ? -1 : len;
    }
};