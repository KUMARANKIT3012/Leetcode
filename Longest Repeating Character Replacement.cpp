class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>count;
        int l = 0;
        int res = 0;
        for(int r = 0; r < s.length(); r++){
            count[s[r]]++;

            int maxcount = 0;
            for(auto x : count){
                maxcount = max(maxcount, x.second);
            }

            while((r - l + 1) - maxcount > k){
                count[s[l]]--;
                l++;
                maxcount = 0;
                for(auto x : count){
                    maxcount = max(maxcount, x.second);
                }
            }
            res = max(res, r - l +1);
        }
        return res;
    }
};
