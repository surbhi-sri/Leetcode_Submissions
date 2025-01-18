class Solution {
public:
    void solve(int ind, string& s, string &digit, vector<string>& ans,
               vector<string> alpha) {
        if (ind == digit.size()){
            ans.push_back(s);
            return;
        }

        for(char c: alpha[digit[ind]-'0']){
            s.push_back(c);
             solve(ind+1, s, digit, ans, alpha);
            s.pop_back(); 
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> alpha = {"",    "",    "abc",  "def", "ghi",
                                "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s;
        vector<string> ans;
        solve(0, s, digits, ans, alpha);
        return ans;
    }
};