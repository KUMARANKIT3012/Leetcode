class Solution {
  public:
    int findMin(int n) {
        // code here
        int coins = 0;
        
        coins += n/10;
        n %= 10;
        
        coins += n/5;
        n %= 5;
        
        coins += n/2;
        n %= 2;
        
        coins += n;
        
        return coins;
    }
};
