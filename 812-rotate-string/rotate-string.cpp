class Solution {
public:
    bool rotateString(string s, string goal) {
      int n=s.size();
      int m=goal.size();
      if(n!=m) return 0;
   
   if(s==goal) return 1;

      queue<char> q1, q2;
      for(int i=0;i<n;i++){
        q1.push(s[i]);
        q2.push(goal[i]);
      }
    
     for(int i=0;i<n-1;i++){
        char c=q2.front();
        q2.pop();
        q2.push(c);
          if(q1==q2) return 1;
     }

      return 0;


    }
};