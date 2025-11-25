class Solution {
public:
    int smallestRepunitDivByK(int k) {
      if(k%2==0 || k%5==0) return -1;

      long long ans=1;
      int cnt=1;

      while(ans%k!=0){
        ans=(ans*10+1)%k;
        cnt++;
      }  
      return cnt;
    }
};