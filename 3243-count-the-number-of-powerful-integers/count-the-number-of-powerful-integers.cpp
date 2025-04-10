class Solution {
public:
    long long solve(string& str, int limit, string& s) {
        int rlen = str.length() - s.length();

        if (rlen < 0)
            return 0;

        string trailString = str.substr(rlen);

        long long cnt = 0;
        for (int i = 0; i < rlen; i++) {
            long long digit = str[i] - '0';

            if (digit <= limit)
                cnt += digit * pow(limit + 1, rlen - i - 1);
            else {
                cnt += pow(limit + 1, rlen - i);
                return cnt;
            }
        }

        if (trailString >= s)
            cnt += 1;

        return cnt;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string startstr = to_string(start - 1);
        string finishstr = to_string(finish);

        return solve(finishstr, limit, s) - solve(startstr, limit, s);
    }
};