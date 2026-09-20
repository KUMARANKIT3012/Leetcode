class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int pos = 0;
        int underscore = 0;

        for(char c : moves) {
            if(c == 'L') pos--;
            else if(c == 'R') pos++;
            else underscore++;
        }

        return abs(pos) + underscore;
    }
};
