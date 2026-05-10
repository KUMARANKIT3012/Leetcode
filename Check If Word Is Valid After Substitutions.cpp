class Solution {
public:
    bool isValid(string s) {
        string temp;

        for (char c : s) {
            temp += c;

            if (temp.size() >= 3 &&
                temp[temp.size() - 3] == 'a' &&
                temp[temp.size() - 2] == 'b' &&
                temp[temp.size() - 1] == 'c') {

                temp.pop_back();
                temp.pop_back();
                temp.pop_back();
            }
        }

        return temp.empty();
    }
};
