class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int sum = ((purchaseAmount + 5) / 10) * 10;
        return 100 - sum;
    }
};
