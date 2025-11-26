class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        int i = 0;
        int j = 0;
        int n1 = a.size();
        int n2 = b.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> unionarr;
        while(i<n1 && j<n2){
            if(a[i] < b[j]){
                if(unionarr.empty() || unionarr.back() != a[i]){
                    unionarr.push_back(a[i]);
                    
                }
                i++;
            }
            else if(a[i] > b[j]){
                if(unionarr.empty() || unionarr.back() != b[j]){
                    unionarr.push_back(b[j]);
                    
                }
                j++;
            }
            else if (a[i] == b[j]){
                if(unionarr.empty() || unionarr.back() != a[i]){
                    unionarr.push_back(a[i]);
                    
                }
                i++;
                    j++;
            }
        }
        while(i < n1){
            if(unionarr.empty() || unionarr.back() != a[i]){
                unionarr.push_back(a[i]);
                
            }
            i++;
        }
        while(j < n2){
            if(unionarr.empty() || unionarr.back() != b[j]){
                unionarr.push_back(b[j]);
                
            }
            j++;
        }
        return unionarr;
    }
};
