class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> seen(26, false);

        for(char ch : sentence){
            if(isalpha(ch)){
                ch = tolower(ch);
                seen[ch - 'a'] = true;
            }
        }

        for(bool val : seen){
            if(!val) return false;
        }
        return true;
    }
};
