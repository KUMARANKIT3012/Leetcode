#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        vector<int> left_pool(26, 0);
        int odd_cnt = 0;
        string mid = "";
        
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_cnt++;
                mid = string(1, (char)('a' + i));
            }
            left_pool[i] = count[i] / 2;
        }
        
        if (odd_cnt > 1) {
            return "";
        }
        
        int half = n / 2;
        
        bool can_match_all = true;
        vector<int> temp_pool = left_pool;
        string cand1_left = "";
        
        for (int i = 0; i < half; ++i) {
            if (i >= target.size()) {
                for(int c = 0; c < 26; ++c) {
                    if (temp_pool[c] > 0) {
                        cand1_left.append(temp_pool[c], (char)('a' + c));
                        temp_pool[c] = 0;
                    }
                }
                break;
            }
            int c = target[i] - 'a';
            if (c >= 0 && c < 26 && temp_pool[c] > 0) {
                temp_pool[c]--;
                cand1_left += target[i];
            } else {
                can_match_all = false;
                break;
            }
        }
        
        if (can_match_all) {
            string full = cand1_left + mid;
            string rev = cand1_left;
            reverse(rev.begin(), rev.end());
            full += rev;
            if (full > target) {
                return full;
            }
        }
        
        int max_pos = 0;
        temp_pool = left_pool;
        for (int i = 0; i < half; ++i) {
            if (i >= target.size()) break;
            int c = target[i] - 'a';
            if (c >= 0 && c < 26 && temp_pool[c] > 0) {
                temp_pool[c]--;
                max_pos++;
            } else {
                break;
            }
        }
        
        int start_pos = min(max_pos, half - 1);
        if (start_pos >= (int)target.size()) {
            start_pos = (int)target.size() - 1;
        }
        
        if (start_pos < 0) {
            if (n == 1 && s > target) return s;
            return "";
        }
        
        vector<int> rem = left_pool;
        for (int i = 0; i < start_pos; ++i) {
            rem[target[i] - 'a']--;
        }
        
        for (int pos = start_pos; pos >= 0; --pos) {
            int target_c = target[pos] - 'a';
            int best_c = -1;
            
            for (int c = target_c + 1; c < 26; ++c) {
                if (rem[c] > 0) {
                    best_c = c;
                    break;
                }
            }
            
            if (best_c != -1) {
                string ans_left = target.substr(0, pos);
                ans_left += (char)('a' + best_c);
                rem[best_c]--;
                
                for (int c = 0; c < 26; ++c) {
                    if (rem[c] > 0) {
                        ans_left.append(rem[c], (char)('a' + c));
                    }
                }
                
                string full = ans_left + mid;
                string rev = ans_left;
                reverse(rev.begin(), rev.end());
                full += rev;
                return full;
            }
            
            if (pos > 0) {
                rem[target[pos - 1] - 'a']++;
            }
        }
        
        return "";
    }
};
