class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        stack<string> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (!str.empty()){
                    st.push(str);
                str = "";
            }
        }
        else str += s[i];
    }
    if(!str.empty())
        st.push(str);
    string ans = "";
    while (!st.empty()) {
        ans += st.top() + " ";
        st.pop();
    }
    ans.pop_back();
    return ans;
}
}
;