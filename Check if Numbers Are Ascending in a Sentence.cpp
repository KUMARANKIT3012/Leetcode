class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int>v;
        int num = 0;
        bool building = false;

        for(char c : s){
            if(isdigit(c)){
                num = num * 10 + (c - '0');
                building = true;
            }
            else{
                if(building){
                    v.push_back(num);
                    num = 0;
                    building = false;
                }
            }
        }
        if(building) v.push_back(num);

        for(int i = 1; i<v.size(); i++){
            if(v[i-1] >= v[i]){
                return false;
            }
        }
        return true;
    }
};
