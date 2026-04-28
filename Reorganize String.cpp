class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for(char ch : s) {
            freq[ch]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto &it : freq) {
            pq.push({it.second, it.first});
        }

        string result = "";

        while(pq.size() > 1) {
            auto [cnt1, ch1] = pq.top(); pq.pop();
            auto [cnt2, ch2] = pq.top(); pq.pop();

            result += ch1;
            result += ch2;

            if(--cnt1 > 0) pq.push({cnt1, ch1});
            if(--cnt2 > 0) pq.push({cnt2, ch2});
        }

        if(!pq.empty()) {
            auto [cnt, ch] = pq.top();
            if(cnt > 1) return "";
            result += ch;
        }

        return result;
    }
};
