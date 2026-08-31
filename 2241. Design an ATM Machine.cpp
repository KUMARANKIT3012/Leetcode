class ATM {
public:
    vector<long long> cnt = vector<long long>(5, 0);
    vector<int> notes = {20, 50, 100, 200, 500};
    
    ATM() {
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; i++){
            cnt[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5, 0);

        for(int i = 4; i >= 0; i--){
            long long take = min(cnt[i], (long long)amount / notes[i]);

            ans[i] = take;
            amount -= take * notes[i];
        }

        if(amount != 0){
            return {-1};
        }

        for(int i = 0; i < 5; i++){
            cnt[i] -= ans[i];
        }

        return ans;
    }
};
