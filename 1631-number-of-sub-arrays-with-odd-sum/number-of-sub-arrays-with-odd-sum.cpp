class Solution {
public:
#define mod 1000000007

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        int sum = 0;
        int cnt = 0;

        int even = 1;
        int odd = 0;

        for (int i = 0; i < n; i++) {
            sum +=arr[i];

            if(sum%2==0){
                cnt= (cnt+odd)%mod;
                even++;
            }else{
               cnt= (cnt+even)%mod;
                odd++;  
            }
        }

        return cnt;
    }
};