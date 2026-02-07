class Solution {
public:
    int minimumDeletions(string s) {
        int cnt = s.size();
        int cnta = 0;
        int cntb = 0;
        for (char c : s)
            cnta += (c == 'a');

        for (char c : s) {
            cnta -= (c == 'a');
            cnt = min(cnt, cnta + cntb);
            cntb += (c == 'b');
        }
        return cnt;
    }
};