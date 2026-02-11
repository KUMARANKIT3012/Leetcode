class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0;
        int n = cardPoints.size();
        for(int i = 0; i<k; ++i){
            leftSum += cardPoints[i];
        }
        int maxScore = leftSum;
        int rightSum = 0;
        for(int i = 0; i<k; ++i){
            leftSum -= cardPoints[k - 1 - i];
            rightSum += cardPoints[n - 1 - i];
            maxScore = max(maxScore, leftSum + rightSum);
        }
        return maxScore;
    }
};
