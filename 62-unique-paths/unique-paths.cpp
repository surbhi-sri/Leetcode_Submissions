class Solution {
public:
    int uniquePaths(int m, int n) {
        //here we will use combination
        //total number of direction :n
        //like in 2x3 matrix= there will be two right as r and one down as d;
        //so total number of combination will :nCr  or nCd
        // ans: rrd, rdr, drr;

        int N=m-1+n-1;
        int direction =min(m-1,n-1);

        long long res=1;

        for(int i=1; i<=direction; i++){
            res = res*(N-i+1)/i;
        }

        return res;
    }
};