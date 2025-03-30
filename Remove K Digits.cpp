class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        // Traverse the number
        for (char digit : num) {
            // Remove larger digits from stack and replace with smaller number 
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }
        
        // Remove remaining k digits from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        // Build the final result stack me se 
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        // Reverse karke return karna hai
        reverse(result.begin(), result.end());
        
        // Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }
        
        // If all digits were removed, return "0"
        return (i == result.size()) ? "0" : result.substr(i);
    }
};
