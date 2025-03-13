class Solution {
public:
    void totalShift(vector<int>& updates, vector<vector<int>>& shifts, int n) {
        for (int i = 0; i < n; i++) {
            int l = shifts[i][0];
            int r = shifts[i][1];
            int shift = shifts[i][2];

            if (shift == 0) {
                updates[l] -= 1;
                if (r + 1 < updates.size())
                    updates[r + 1] += 1;
            } else {
                updates[l] += 1;
                if (r + 1 < updates.size())
                    updates[r + 1] -= 1;
            }
        }
    }

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> updates(n, 0);

        int ns = shifts.size();

        totalShift(updates, shifts, ns);

        for (int i = 1; i < n; i++)
            updates[i] = updates[i] + updates[i - 1];

        string str=s;

        for (int i = 0; i < n; i++) {
            int change = ((s[i] - 'a' + updates[i]) % 26 + 26) % 26; 

            str[i] ='a' + change;
        }

        return str;
    }
};