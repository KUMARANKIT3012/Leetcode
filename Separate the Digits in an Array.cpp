class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;

        for (int num : nums) {
            vector<int> temp;

            while (num > 0) {
                temp.push_back(num % 10);
                num /= 10;
            }

            reverse(temp.begin(), temp.end());

            for (int digit : temp) {
                result.push_back(digit);
            }
        }

        return result;
    }
};
