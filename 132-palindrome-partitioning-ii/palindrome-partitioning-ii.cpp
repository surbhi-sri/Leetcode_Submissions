class Solution {
public:
    bool ispalindrome(int i, int j, string& temp) {
       if(i==j) return 1;

        while (i <= j) {
            if (temp[i] != temp[j])
                return 0;
            i++;
            j--;
        }

        return 1;
    }

   
    int minCut(string s) {
        int n = s.size();

        vector<int>  dp(n + 1, 0);

        for(int i=n-1; i>=0; i--){
        int min_cut = n;

        for (int ind = i; ind < n; ind++) {

            if (ispalindrome(i, ind, s)) {
                int cut = 1 + dp[ind + 1];
                min_cut=min(min_cut, cut);
            }
        }

         dp[i] = min_cut;
        }

        return dp[0]-1;
    }
};