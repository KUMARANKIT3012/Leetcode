class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int count = 0;
        stringstream ss(sentence);
        string word;
        while(ss >> word){
            count++;
            if(word.find(searchWord) == 0){
                return count;
            }
        }
        return -1;
    }
};
