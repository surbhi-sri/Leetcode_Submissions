class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
     int n=derived.size();

     int takingBit=1;
     int temp=takingBit;
     
     for(int i=0; i<n-1; i++){
        if(derived[i+1]==1) temp=!temp;
     }

     if(derived[0]==1) temp=!temp;

     return takingBit==temp;
    }
};