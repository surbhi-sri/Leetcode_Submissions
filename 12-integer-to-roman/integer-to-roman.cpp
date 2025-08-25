class Solution {
public:
    string intToRoman(int num) {
        string ans="";

       int m=num/1000; 
       while(m--) ans +="M";

       num%=1000;
       int c_d=num/100;

       if(c_d<=3){
        while(c_d--) ans+="C";
       }else if(c_d==4) ans+="CD";
        else if(c_d>=5 & c_d<9) {
            ans+="D";
           c_d-=5;
           while(c_d--) ans+="C"; 
        }else ans+="CM";

        num%=100;
       int x=num/10; 
        if(x<=3){
        while(x--) ans+="X";
       }else if(x==4) ans+="XL";
        else if(x>=5 & x<9) {
            ans+="L";
           x-=5;
           while(x--) ans+="X"; 
        }else ans+="XC";

       num%=10;
       int i_v=num; 
       if(i_v<=3){
        while(i_v--) ans+="I";
       }else if(i_v==4) ans+="IV";
        else if(i_v>=5 & i_v<9) {
            ans+="V";
           i_v-=5;
           while(i_v--) ans+="I"; 
        }else ans+="IX";

        return ans;
               
    }
};