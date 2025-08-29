class Solution {
public:
    long long flowerGame(int n, int m) {
        int en=n/2;
        int on=n-en;
        int em=m/2;
        int om=m-em;

        long long p1=1ll*en*om; 
        long long p2=1ll*on*em;

        return p1+p2; 
    }
};