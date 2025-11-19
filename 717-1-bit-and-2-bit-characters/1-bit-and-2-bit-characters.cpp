class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
       if(bits[n-1]!=0) return 0;

       for(int i=0; i<n; i++){
        if(bits[i]==0) {
            if(i==n-1) return 1;
            continue;
        }
        
        else i++;
       } 
       return 0;
    }
};