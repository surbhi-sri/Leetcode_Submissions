class Solution {
public:

   bool isValdid(string s){
    int cnt=0;
    for (char c : s){
    if(c=='(') cnt++;
    else if(c==')') cnt--;
    if(cnt<0) return 0;
    }
    return cnt==0;
   }

   void solve(string &s, vector<string> &ans, int n){
    if(s.size()==n){
        if(isValdid(s)) ans.push_back(s);
        return;
    }
    
    s.push_back('(');
    solve(s, ans, n);
    s.pop_back();
     s.push_back(')');
    solve(s, ans, n);
    s.pop_back();

   }

    vector<string> generateParenthesis(int n) {
    vector<string> ans;
     string s;
     solve(s, ans, 2*n);
     return ans;   
    }
};