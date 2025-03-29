class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int asteroid : asteroids) {
            bool destroyed = false;

            while (!st.empty() && asteroid < 0 && st.top() > 0) {  // Collision case
                if (abs(st.top()) < abs(asteroid)) {
                    st.pop();  // Destroy the right-moving asteroid
                } else if (abs(st.top()) == abs(asteroid)) {
                    st.pop();  // Both asteroids destroy each other
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;  // left-moving asteroid is destroyed
                    break;
                }
            }

            if (!destroyed) {
                st.push(asteroid);
            }
        }
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
