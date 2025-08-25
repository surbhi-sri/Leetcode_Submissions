class Solution {
public:
    int myAtoi(string s) {
      int i=0;
      int n=s.size();
      int sign=0;
      long long num=0;

      while(s[i]==' ') i++;

      if(s[i]=='-' || s[i]=='+') {
       if(s[i]=='-') sign=1;
      i++; 
      }

     while(s[i]=='0') i++;

     while(s[i]>='0' && s[i]<='9' ){
        num=num*10+ s[i]-'0';
        
        if(num>INT_MAX){
            if(sign) return INT_MIN;
            else return INT_MAX;
        }

        i++;
     }

      if(sign) num=0-num;

      return num;
    }
};