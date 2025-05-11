class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int>prefixmap;
        int prefixsum = 0;
        int maxlen  = 0;
        for(int i =0; i<n; i++){
            prefixsum+=arr[i];
            
            if(prefixsum == 0){
                maxlen = i+1;
            }
            
            if(prefixmap.find(prefixsum) != prefixmap.end()){
                maxlen = max(maxlen, i - prefixmap[prefixsum]);
            }
            else{
                prefixmap[prefixsum] = i;
            }
        }
        return maxlen;
        
    }
};
