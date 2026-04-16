class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        // int digits = 0;
        
        for(int i = n-1; i>=0; i--){
            int sum = num[i] + k;
            num[i] = sum%10;
            k = sum/10;
        }

        while(k > 0){
            num.insert(num.begin(), k%10);
            k/=10;
        }

        return num;
    }
};
