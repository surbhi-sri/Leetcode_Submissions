class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;

        for(int i=31; i>=0; i--){
            int bit1=(a>>i)&1;
            int bit2=(b>>i)&1;
            int bit3=(c>>i)&1;
            if(bit3==0){
                cnt+=(bit1!=0);
                cnt+=(bit2!=0);
            }else{
                cnt+=((bit1||bit2)==0);
            }
        }

        return cnt;
    }
};