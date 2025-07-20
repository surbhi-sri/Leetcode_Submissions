class Solution {
public:

  int n;

    bool solve(int ind, string s, unordered_set<string> &st, vector<int> &dp){
        if(ind==n) return 1;

        if(dp[ind]!=-1) return dp[ind];

        string str="";

        for(int i=ind; i<n; i++){
            str +=s[i];
            if(st.count(str)){
                if(solve(i+1, s, st, dp)) return dp[ind]= 1;
            }
        }

        return dp[ind] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        n=s.size();
        vector<int> dp(301, -1);
        return solve(0, s, st, dp);
    }
};