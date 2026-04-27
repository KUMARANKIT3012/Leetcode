class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> mp;
        int count = 0;

        for(char c : jewels){
            mp.insert(c);
        }

        for(char s : stones){
            if(mp.find(s) != mp.end()){
                count++;
            }
        }
        return count;
    }
};
