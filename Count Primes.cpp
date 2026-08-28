class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n+1, true);
        int count=0;

        for(int i=2; i<n; i++){
            if(isprime[i]){
                count++;

                for(int j=i*2; j<n; j=j+i){
                    isprime[j]=false;
                }
            }
        }
        return count;
    }
};


// new code : 

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        vector<char> isPrime(n, 1);
        
        for (int i = 3; i * i < n; i += 2) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j] = 0;
                }
            }
        }
        
        int count = 1; 
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i]) count++;
        }
        
        return count;
    }
};

