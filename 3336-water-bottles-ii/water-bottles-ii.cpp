class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
       int cnt=0;

       while(numBottles >=numExchange){
        cnt +=numExchange;
         numBottles+=(1-numExchange);
         numExchange++;
       }
       return cnt+numBottles;
    }
};