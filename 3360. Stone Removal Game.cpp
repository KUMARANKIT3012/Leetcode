class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
        bool alice = true;
        while (n >= remove) {
            n -= remove;
            remove--;
            if (remove == 0) break;
            alice = !alice;
        }
        return !alice;
    }
};
