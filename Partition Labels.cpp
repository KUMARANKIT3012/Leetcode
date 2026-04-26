class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26);
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        vector<int> res;
        int size = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            size++;
            end = max(end, lastIndex[s[i] - 'a']);

            if (i == end) {
                res.push_back(size);
                size = 0;
            }
        }

        return res;
    }
};
