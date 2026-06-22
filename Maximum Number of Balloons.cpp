class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);

        for (char ch : text) {
            freq[ch - 'a']++;
        }

        freq['l' - 'a'] /= 2;
        freq['o' - 'a'] /= 2;

        return min({freq['b' - 'a'],
                    freq['a' - 'a'],
                    freq['l' - 'a'],
                    freq['o' - 'a'],
                    freq['n' - 'a']});
    }
};
