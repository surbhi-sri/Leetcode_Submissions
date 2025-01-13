class Solution {
public:
   
   int p = 1e9 + 7;

    long long power(long long x, long long n){
    if(n==0) return 1;
    
    long long half=power(x, n/2) % p;

    return (n%2==0) ? (half*half)%p : (half*half*x)%p;

    }

    int countGoodNumbers(long long n) {
        long long cnt_4s = n / 2;
        long long cnt_5s = n - n / 2;
         
         long long ans=(power(4, cnt_4s) % p * power(5, cnt_5s) % p)%p;

         return (int)ans;
    }
};