class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;

        for (char c : s)
            if (isVowel(c))
                v.push_back(c);

        unordered_map<char, int> freq;
        for (char c : v) freq[c]++;

        unordered_map<char, int> first;
        for (int i = 0; i < s.size(); i++)
            if (isVowel(s[i]) && !first.count(s[i]))
                first[s[i]] = i;

        sort(v.begin(), v.end(), [&](char a, char b) {
            if (freq[a] != freq[b]) return freq[a] > freq[b];
            return first[a] < first[b];
        });

        int j = 0;
        for (int i = 0; i < s.size(); i++)
            if (isVowel(s[i]))
                s[i] = v[j++];

        return s;
    }

    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
};©leetcode
