class Solution {
public:
    int minimumDeletions(string s) {
      int cnt=0;  
      stack<char> st;
      for(char c:s){
        if(c=='a' && !st.empty() && st.top()=='b'){
            st.pop();
            cnt++;
        }else st.push(c);
      }
      return cnt;
    }
};