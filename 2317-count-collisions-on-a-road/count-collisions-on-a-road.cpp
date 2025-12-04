class Solution {
public:
    int countCollisions(string d) {
        stack<char> st;
        int collision = 0;
        for (char c : d) {
            if (c == 'R')
                st.push(c);
            else if (c == 'L') {
                if (st.empty())
                    continue;
                else if (st.top() == 'R') {
                    collision += 2;
                    st.pop();
                  while (!st.empty() && st.top() == 'R') {
                        collision += 1;
                        st.pop();
                    }
                    st.push('S');
                } else
                    collision += 1;

            } else {
                if (st.empty())
                    st.push(c);
                else if (st.top() == 'S')
                    continue;
                else {
                    while (!st.empty() && st.top() == 'R') {
                        collision += 1;
                        st.pop();
                    }
                    st.push(c);
                }
            }
        }
        return collision;
    }
};