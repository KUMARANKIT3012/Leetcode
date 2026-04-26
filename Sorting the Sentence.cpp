class Solution {
public:
    string sortSentence(string s) {
        string word = "";
        vector<string>v(10);
        for(int i = 0; i<s.size(); i++){

            if(s[i] >= 48 && s[i] <= 57){ // it is a number : ASCII
                v[s[i] - 48] = word + " "; // 51 - 48 = 3
                word = "";
                i++;
            }
            else word += s[i];
        }
        string ans;
        for(string x : v){
            ans += x; // end space 
        }
        ans.pop_back(); // to remove space aakhri mein 
        return ans;
    }
};
