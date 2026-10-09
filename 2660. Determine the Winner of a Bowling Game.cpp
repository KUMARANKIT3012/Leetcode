class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = player1.size();
        int score1 = 0, score2 = 0;

        for (int i = 0; i < n; i++) {
            int a = player1[i];
            int b = player2[i];

            if (i > 0 && player1[i - 1] == 10 ||
                i > 1 && player1[i - 2] == 10) {
                a *= 2;
            }

            if (i > 0 && player2[i - 1] == 10 ||
                i > 1 && player2[i - 2] == 10) {
                b *= 2;
            }

            score1 += a;
            score2 += b;
        }

        if (score1 > score2) return 1;
        if (score2 > score1) return 2;
        return 0;
    }
};
