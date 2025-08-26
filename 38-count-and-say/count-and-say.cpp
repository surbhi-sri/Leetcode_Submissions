class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string s = countAndSay(n - 1);
        string ans = "";
        char c =s[0];
        int cnt = 1;
        int len=s.size();
        for (int i=1; i<len; i++) {
         
            if (s[i] == c)
                cnt++;
            else {
                ans += to_string(cnt);
                ans.push_back(c);
                c = s[i];
                cnt = 1;
            }
        }
        ans += to_string(cnt);
        ans.push_back(c);

        return ans;
    }
};