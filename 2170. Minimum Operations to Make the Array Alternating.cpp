class Solution {
public:
    pair<int,int> topTwo(unordered_map<int,int>& mp) {
        pair<int,int> first = {-1, 0}, second = {-1, 0};
        for (auto &p : mp) {
            if (p.second > first.second) {
                second = first;
                first = p;
            }
            else if (p.second > second.second) {
                second = p;
            }
        }
        return {first.first, first.second * 100000 + second.second};
    }

    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> even, odd;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                even[nums[i]]++;
            else
                odd[nums[i]]++;
        }
        pair<int,int> e1 = {-1,0}, e2 = {-1,0};
        pair<int,int> o1 = {-1,0}, o2 = {-1,0};
        for (auto &p : even) {
            if (p.second > e1.second) {
                e2 = e1;
                e1 = p;
            }
            else if (p.second > e2.second) {
                e2 = p;
            }
        }

        for (auto &p : odd) {
            if (p.second > o1.second) {
                o2 = o1;
                o1 = p;
            }
            else if (p.second > o2.second) {
                o2 = p;
            }
        }

        int evenCnt = (nums.size() + 1) / 2;
        int oddCnt = nums.size() / 2;
        if (e1.first != o1.first) {
            return nums.size() - (e1.second + o1.second);
        }
        int option1 = e1.second + o2.second;
        int option2 = e2.second + o1.second;
        return nums.size() - max(option1, option2);
    }
};
