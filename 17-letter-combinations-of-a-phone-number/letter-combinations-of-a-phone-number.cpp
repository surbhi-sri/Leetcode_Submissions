class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> alpha = {"",    "",    "abc",  "def", "ghi",
                                "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s;
        vector<string> ans;
       ans.push_back("");
      for(auto n: digits){
        vector<string> temp;
        for(auto a : alpha[n-'0']){
          for(auto c: ans) temp.push_back(c+a); 
        }
        ans=temp; 
      }

        return ans;
    }
};