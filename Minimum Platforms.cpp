class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 1;
        int j = 0;
        int platform_needed = 1;
        int max_platform = 1;
        
        while(i<n && j<n){
            if(arr[i] <= dep[j]){
                platform_needed++;
                i++;
            }
            else{
                platform_needed--;
                j++;
            }
            max_platform = max(max_platform, platform_needed);
        }
        return max_platform;
        
    }
};
