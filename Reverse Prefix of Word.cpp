class Solution {
public:
    string reversePrefix(string word, char ch) {
        int countch = -1;
        for(int i = 0; i<word.length(); i++){
            if(word[i] == ch){
                countch = i;
                break;
            }
        }

        if(countch == -1) return word;

        int st = 0;
        int end = countch;

        while(st<end){
            swap(word[st], word[end]);
            st++;
            end--;
        }
        return word;
    }
};
