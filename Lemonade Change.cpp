class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        int countfive = 0;
        int countten = 0;
        int counttw = 0;

        for(int i = 0; i < n; i++){
            if(bills[i] == 5){
                countfive++;
            }
            else if(bills[i] == 10){
                countten++;
                if(countfive) countfive--;
                else return false;
            }

            else if(bills[i] == 20){
                counttw++;
                if(countten && countfive){ 
                    countten--;
                    countfive--;
                }
                else if(countfive >= 3){
                    countfive -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
