class Solution {
public:
    double myPow(double x, int n) {
        double pow = 1;
        long long nn=n;
        if (nn < 0) 
            nn = -1*nn;


        while(nn){
            if(nn%2){
                pow *=x;
                nn -=1;
            }else{
                x *=x;
                nn /=2;
            }
        }

        if (n<0)
            return (1.0 / pow);

        return pow;
    }
};