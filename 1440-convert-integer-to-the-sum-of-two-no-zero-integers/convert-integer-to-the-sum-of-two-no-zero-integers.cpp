class Solution {
public:

    bool valid(int num, int n){
        string s1=to_string(num);
        string s2=to_string(n-num);

        for(char &c:s1){
            if(c=='0') return 0;
        }
        for(char c:s2){
            if(c=='0') return 0;
        }
        return 1;
    }

    vector<int> getNoZeroIntegers(int n) {
       int i=1;

        while(!valid(i, n)){
            i++;
            }
       
       return {i, n-i};
    }
};