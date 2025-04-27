class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool xorr=0;
     
          for(int d: derived)
          xorr ^=d;

          return xorr==0;

    }
};