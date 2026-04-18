class Solution {
public:
    string countAndSay(int n) {
        string result = "1";  // base case

        for(int i = 2; i <= n; i++) {
            string temp = "";
            int count = 1;

            for(int j = 1; j < result.size(); j++) {
                if(result[j] == result[j - 1]) {
                    count++;
                } else {
                    temp += to_string(count);
                    temp += result[j - 1];
                    count = 1;
                }
            }

            // last group
            temp += to_string(count);
            temp += result.back();

            result = temp;
        }

        return result;
    }
};
