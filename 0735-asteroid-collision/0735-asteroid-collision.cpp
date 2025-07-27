class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                int top = st.top();
                if (abs(top) < abs(asteroids[i])) {
                    st.pop(); // top gets destroyed
                    continue; // current asteroid may still collide with more
                } else if (abs(top) == abs(asteroids[i])) {
                    st.pop(); // both destroy each other
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // current gets destroyed
                    break;
                }
            }

            if (!destroyed) {
                st.push(asteroids[i]);
            }
        }
        vector<int> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};