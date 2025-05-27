class Solution {
public:
    int differenceOfSums(int n, int m) {
        
        int total_sum= (n*(n+1))/2;  // from 1 to n

        int k= n/m;  //total Number Divisible By M

        int sum2= (m*k*(k+1))/2;   //sum Divisible By M

        return total_sum-2*sum2;  
    }
};