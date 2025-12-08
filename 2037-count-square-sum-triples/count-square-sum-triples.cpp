class Solution {
public:
    int countTriples(int n) {
      if(n<3) return 0;
       
       int  cnt=0;

       for(int i=1; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int s= i*i + j*j;
            int x=sqrt(s);

            if(x*x==s && x<=n) cnt+=2;
        }
       }

       return cnt;
    }
};