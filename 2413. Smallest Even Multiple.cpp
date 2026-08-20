class Solution {
public:
    int smallestEvenMultiple(int n) {
        int count = 2;
        while(count % 2 != 0 || count % n != 0){
            count++;
        }
        return count;
    }
};
