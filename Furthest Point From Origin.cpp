class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countl = 0;
        int countr = 0;
        int count_ = 0;
        int n = moves.length();
        int result = 0;
        for(int i = 0; i<n; i++){
            if(moves[i] == 'L'){
                countl++;
            }
            else if(moves[i] == 'R'){
                countr++;
            }
            else{
                count_++;
            }
        }
        result = abs(countl - countr) + count_;
        return result;
    }
};
