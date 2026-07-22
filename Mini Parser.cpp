/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     NestedInteger();
 *     NestedInteger(int value);
 *     bool isInteger() const;
 *     int getInteger() const;
 *     void setInteger(int value);
 *     void add(const NestedInteger &ni);
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[')
            return NestedInteger(stoi(s));

        stack<NestedInteger> st;

        int i = 0;
        while (i < s.size()) {
            if (s[i] == '[') {
                st.push(NestedInteger());
                i++;
            }
            else if (s[i] == ']') {
                NestedInteger cur = st.top();
                st.pop();

                if (st.empty())
                    return cur;

                st.top().add(cur);
                i++;
            }
            else if (s[i] == ',') {
                i++;
            }
            else {
                int sign = 1;
                if (s[i] == '-') {
                    sign = -1;
                    i++;
                }

                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                st.top().add(NestedInteger(sign * num));
            }
        }

        return NestedInteger();
    }
};
