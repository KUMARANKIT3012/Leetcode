class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        
        vector<pair<double, pair<int,int>>> items;
        
        for(int i = 0; i<n; i++){
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, {wt[i], val[i]}});
        }
        
        sort(items.begin(), items.end(),
            [](auto &a, auto &b) {
                return a.first > b.first;
            });
            
        double totalValue = 0.0;
        
        for(auto &item : items){
            int weight = item.second.first;
            int value = item.second.second;
            
            if(capacity >= weight){
                totalValue += value;
                capacity -= weight;
            }
            
            else{
                totalValue += item.first * capacity;
                break;
            }
        }
        return totalValue;
    }
};
