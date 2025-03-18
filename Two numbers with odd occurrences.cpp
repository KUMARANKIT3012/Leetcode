class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long xorr = 0;
        // Step 1: Find XOR of all elements
        for(int i = 0; i < N; i++){
            xorr = xorr ^ Arr[i];
        }
        // Step 2: Find rightmost set bit
        long long rightmost = xorr & -xorr; 
        // Step 3: Divide numbers into two groups
        long long b1 = 0, b2 = 0;
        for(int i = 0; i < N; i++){
            if(Arr[i] & rightmost){
                b1 = b1 ^ Arr[i];
            }
            else{
                b2 = b2 ^ Arr[i];
            }
        }
        // descending order mein return karna hai:
        if(b1 < b2) swap(b1, b2);
        return {b1, b2};
    }
};
